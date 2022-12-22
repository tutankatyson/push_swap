/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:14:22 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/22 21:27:13 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


static void sf_pasa_media(my_stack *a, my_stack *b)
{
	int media, size;

	media = ft_media(a);
	size = a->last + 1;

	while(a->last - 1 > size / 2)
	{
		if(a->stack[0] > media)
			push(b,a);
		else
			rotate(a);
	}
}



static int sf_algoritmo1_2(my_stack *sta, my_stack *stb)
{
							//Toma el máximo o el mínimo y hace push al otro stack
	int max;				//ahora toma el camino más corto para llegar al numero a cambiar		
	int min;
	int imin;
	int imax;

	max = ft_max(sta);
	min = ft_min(sta);

	while (sta->last >= 0)
	{
		if(sta->stack[0] == max)
		{
			push(stb,sta);					//printf("\n---------------------> push");print(sta,stb);
			max = ft_max(sta);
		}
		else if(sta->stack[0] == min)
		{
			push(stb,sta);					//printf("\n---------------------> push");print(sta,stb);
			if(stb->last > 0)
				rr(stb,sta);				//printf("\n---------------------> rot");print(sta,stb);}
			min = ft_min(sta);
		}else								//Busca max y min y va a por el más cercano
		{
	//		printf("\n---------------------> GO NEAAREST ---------------------> ");print(sta,stb);
			imin = ft_find_min(sta);
			imax = ft_find_max(sta);	
			if(abs(imin) < abs(imax))
			{
				if(imin > 0)
						rotate(sta);
				if(imin < 0)
						reverse(sta);
			}
			else
			{
				if(imax > 0)
						rotate(sta);
				if(imax < 0)
						reverse(sta);
			}
	//			printf("\n---------------------> GO NEAAREST");print(sta,stb);

		}
	}
	while (stb->stack[0] > stb->stack[stb->last])
	{
		rotate(stb);
	}
	//print(sta,stb);
	//print(sta,stb);
	return 0;
}

static int sf_algoritmo2_2(my_stack *sta, my_stack *stb)
{
							//Toma el máximo o el mínimo y hace push al otro stack
	int max;				//ahora toma el camino más corto para llegar al numero a cambiar		
	int min;
	int imin;
	int imax;

	max = ft_max(sta);
	min = ft_min(sta);

	while (sta->last >= 0)
	{
		if(sta->stack[0] == min)
		{
			push(stb,sta);					//printf("\n---------------------> push");print(sta,stb);
			min = ft_min(sta);
		}
		else if(sta->stack[0] == max)
		{
			push(stb,sta);					//printf("\n---------------------> push");print(sta,stb);
			if(stb->last > 0)
				rrr(stb,sta);				//printf("\n---------------------> rot");print(sta,stb);}
			max = ft_max(sta);
		}else								//Busca max y min y va a por el más cercano
		{
	//		printf("\n---------------------> GO NEAAREST ---------------------> ");print(sta,stb);
			imin = ft_find_min(sta);
			imax = ft_find_max(sta);
			if(abs(imin) < abs(imax))
			{

				if(imin > 0)
					rotate(sta);
				if(imin < 0)
					reverse(sta);
			}
			else
			{
				if(imax > 0)
						rotate(sta);
				if(imax < 0)
						reverse(sta);
			}
	//			printf("\n---------------------> GO NEAAREST");print(sta,stb);

		}
	}

	//print(sta,stb);
	//print(sta,stb);
	return 0;
}


/*********************************************
 * 
 * 		100 -- 1100
 * 		500 -- 19000
 * 		1000 - 67962
 * 
*/
void alg_1_0(my_stack *a, my_stack *b)
{
	sf_pasa_media(a,b);
	sf_algoritmo2_2(a,b);
	sf_algoritmo1_2(b,a);
}