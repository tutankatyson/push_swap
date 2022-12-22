/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:57:26 by marvin            #+#    #+#             */
/*   Updated: 2022/12/09 13:57:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int dealer0(int n, my_stack *a, my_stack *b);
void pasa_media(my_stack *a, my_stack *b);


int main(int argc, char **argv)
{

	my_stack a, b;


	/*Control de errores*/

    if(argc == 1 || !argv){
        printf("\nERROR");
		return 0;
	}

//	printf(CYAN"\n  NUMERO DE ELEMENTOS: %i"RESET,argc-1);

    /*inicializar*/
	
	ft_init(&a, argc, argv);
	ft_init(&b, argc, NULL);

//	dispersion(&a);
//	rotoswap(&a,500);
//	dispersion(&a);

	pasa_media(&a,&b);


//	dealer0(50,&a,&b);		//82
//	dealer(500,&a,&b);		//87






//	rollup_b_pushall(&a,&b);					//(100)1500
//	rollup_b_pushall_2(&a,&b);					//(100)1500
//	rollup_b_pushall_3(&a,&b);					//(20)90 (100)1500
//	PUSH_SWAP(&a,&b);







//	push(&b,&a);
//	print(&a,&b);
//	print(&a1,&b1);
//	printf(GREEN"ORDER"RESET);
//	print(&a,&b);
//	
//	one_stack(&a2);
//	print(&a,&b);
//	print(&a1,&b1);
//	print(&a1,&b1);
//	checkp(&a);
	return 0;
}

/** * * * * P U S H _ S W A P * * * * * **/

int rollup_b_pushall(my_stack *a, my_stack *b)
{
	int cont = 0;

	cont = cont + algoritmo2(a,b);
	cont += push_all(a,b);

	checkp(a);
	printf(YELLOW"\n - rollup_b_pushall - ");
	printf("CONTADOR: %i "RESET,cont);
	return cont;
}

int rollup_b_pushall_2(my_stack *a, my_stack *b)
{
	int cont = 0;

//	print(a,b);
	cont = cont + algoritmo2_1(a,b);

//	print(a,b);
	cont = cont + push_all(a,b);
//	print(a,b);

	/*Resultados*/
	checkp(a);
	printf(YELLOW"\n - rollup_b_pushall_2 - ");
	printf("CONTADOR: %i "RESET,cont);

	return cont;
}

int rollup_b_pushall_3(my_stack *a, my_stack *b)
{


//	print(a,b);
	algoritmo2_2(a,b);

//	print(a,b);
	push_all(a,b);
//	print(a,b);

	/*Resultados*/
	checkp(a);



	return 0;
}

int PUSH_SWAP(my_stack *a, my_stack *b)
{
	int cont = 0;
	int end = 0;
	while (!end)
	{
		cont = cont + ps_all_up(a,b);
		cont = cont + ps_all_down(b,a);
		if(check(a)){
//			checkp(a);
//			printf(YELLOW"\n - PUSH_SWAP - ");
//			printf("CONTADOR: %i "RESET,cont);
			return cont;
		}
	}
	
	return 0;

}

int one_stack(my_stack *a)
{
	int cont = 0;
	int end = 0;

	while (!end)
	{
		if(check(a))
				return cont;
		if(a->stack[0] > a->stack[1])
		{
			swap(a);
			print(a,a);
			cont++;
			if(ft_isorder(a))
			{
				while(!check(a))
				{
					rotate(a);
					print(a,a);
					cont++;
				}
				end = 1;
			}
		}
		else
		{
			rotate(a);
			print(a,a);
			cont++;
		}
	
	}
	

	checkp(a);
	printf(YELLOW"\n - PUSH_SWAP - ");
	printf("CONTADOR: %i "RESET,cont);
	return cont;

}




/** * * * * A L G O R I T M O S * * * * **/

int algoritmo1(my_stack *sta, my_stack *stb)
{
	int cont = 0;
	int max;

	max = ft_max(sta);

	while (sta->last >= 0)
	{
		if(sta->stack[0] == max){
			push(stb,sta);
			cont++;
			max = ft_max(sta);
		}else{
			rotate(sta);
			cont++;
		}
	}
	return cont;
}

int algoritmo2(my_stack *sta, my_stack *stb)
{
	int cont = 0;
	int min;

	min = ft_min(sta);

	while (sta->last >= 0)
	{
		if(sta->stack[0] == min){
			push(stb,sta);
			cont++;
			min = ft_min(sta);
		}else{
			rotate(sta);
			cont++;
		}
	}
	return cont;
}

int algoritmo1_1(my_stack *sta, my_stack *stb)
{
	int cont = 0;
	int max;
	int min;

	max = ft_max(sta);
	min = ft_min(sta);

	while (sta->last >= 0)
	{
		if(sta->stack[0] == max){
			push(stb,sta);
			cont++;
			max = ft_max(sta);
		}else{
			rotate(sta);
			cont++;
		}
		if(sta->stack[0] == min){
			push(stb,sta);
			cont++;
			rotate(stb);
			cont++;
			max = ft_min(sta);
		}else{
			rotate(sta);
			cont++;
		}
	}
	return cont;
}

int algoritmo2_1(my_stack *sta, my_stack *stb)
{
	int cont = 0;			//Toma el máximo o el mínimo y hace push al otro stack
	int max;				//Si 		
	int min;

	max = ft_max(sta);
	min = ft_min(sta);

	while (sta->last >= 0)
	{
		if(sta->stack[0] == min)
		{
			push(stb,sta);				
						//	printf(CYAN"\n---------------------> push"RESET);print(sta,stb);
			cont++;
			min = ft_min(sta);
		}
		else if(sta->stack[0] == max)
		{
			push(stb,sta);			
					//		printf(CYAN"\n---------------------> push"RESET);print(sta,stb);
			if(stb->last > 1)
			{
				rotate(stb);
						//	printf(MAGENTA"\n---------------------> rot B"RESET);print(sta,stb);
			}
			cont = cont + 2;
			max = ft_max(sta);
		}
		else
		{
			rotate(sta);
						//	printf(RED"\n---------------------> rot A"RESET);print(sta,stb);
			cont++;
		}
	}
	while (stb->stack[0] < stb->stack[stb->last])
	{
		cont++;
		rotate(stb);
	}
//	print(sta,stb);
	//print(sta,stb);
	return cont;
}

int algoritmo2_2(my_stack *sta, my_stack *stb)
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
				rotate(stb);				//printf("\n---------------------> rot");print(sta,stb);}
			max = ft_max(sta);
		}else								//Busca max y min y va a por el más cercano
		{
	//		printf("\n---------------------> GO NEAAREST ---------------------> ");print(sta,stb);
			imin = ft_find_min(sta);
			imax = ft_find_max(sta);
			if(abs(imin) < abs(imax))
			{

				if(imin > 0)
					for(int i = 0; i < imin ;i++){
						rotate(sta);}
				if(imin < 0)
					for(int i = 0; i < abs(imin) ;i++){
						reverse(sta);}
			}
			else
			{
				if(imax > 0)
					for(int i = 0; i < imax ;i++ ){
						rotate(sta);}
				if(imax < 0)
					for(int i = 0; i < abs(imax) ;i++ ){
						reverse(sta);}
			}
	//			printf("\n---------------------> GO NEAAREST");print(sta,stb);

		}
	}
	while (stb->stack[0] < stb->stack[stb->last])
	{
		rotate(stb);
	}
	//print(sta,stb);
	//print(sta,stb);
	return 0;
}

int dealer0(int n, my_stack *a, my_stack *b)
{
	/*Control errores*/
	if(n - 1 > a->last)
		return -1;

	/*****************/
	push(b,a);
	push(b,a);
	int cont = 2;
	while (n > 2)
	{
		if(a->stack[0] - b->stack[0] > a->stack[1] - b->stack[1])
		{
			rr(a,b);cont++;
			push(b,a);cont++;
		}
		else
		{
			push(b,a);cont++;
		}
	n--;
	}
	return 0;
}

int dealer(int n, my_stack *a, my_stack *b)
{
	/*Control errores*/
	if(n - 1 > a->last)
		return -1;

	/*****************/
	push(b,a);
	push(b,a);
	int cont = 2;
	while (n > 2)
	{
		if(a->stack[a->last] - b->stack[b->last] > a->stack[1] - b->stack[1])	//Caso rr mejor que rrr
		{
			if(a->stack[0] - b->stack[0] > a->stack[1] - b->stack[1])
			{
				rr(a,b);cont++;
				push(b,a);cont++;
			}
			else
			{
				push(b,a);cont++;
			}
		}
		else
		{
			if(a->stack[0] - b->stack[0] > a->stack[b->last] - b->stack[b->last])
			{
				rrr(a,b);cont++;
				push(b,a);cont++;
			}
			else
			{
				push(b,a);cont++;
			}
		}
		n--;
	}
//	print(a,b);
	return cont;
}

int ordena3(my_stack *st)
{
	if(check(st))
		return 0;
	if(ft_isorder(st))
	{
		if(st->stack[0] > st->stack[1]){
			rotate(st);}												//UP	
		else{
			reverse(st);}												//DOWN
		return 1;
	}
	swap(st);															//SWAP
	if(check(st))
		return 2;
	if(st->stack[0] == ft_max(st))
		rotate(st);														//DOWN
	else
		reverse(st);													//UP									
	return 2;
}

int push_all(my_stack *sta, my_stack *stb)
{
	int cont = 0;

	while (stb->last >= 0)
	{
		cont++;
		push(sta,stb);
	}
	
	return cont;
}

int p_s(my_stack *a, my_stack *b)
{
	push(b,a);
	swap(b);
	return 2;
}

int push_swap_up(my_stack *a, my_stack *b)
{
	push(b,a);
	if(b->stack[0] < b->stack[1])
	{
		swap(b);
		return 2;
	}
	return 1;
}

int push_swap_down(my_stack *a, my_stack *b)
{
	push(b,a);
	if(b->stack[0] > b->stack[1])
	{
		swap(b);
		return 2;
	}
	return 1;
}

int ps_all_down(my_stack *a, my_stack *b)
{
	int cont = 0;

	while (a->last > -1)
	{
		push(b,a);
		cont++;
		if(b->stack[0] > b->stack[1])
		{
			swap(b);
			cont++;
		}
	}
	return cont;
}

int ps_all_up(my_stack *a, my_stack *b)
{
	int cont = 0;

	while (a->last > -1)
	{
		push(b,a);
		cont++;
		if(b->stack[0] < b->stack[1])
		{
			swap(b);
			cont++;
		}
	}
	return cont;
}

int push_swap_n_down(int n, my_stack *origin, my_stack *destiny)
{
	int cont = 1;
	if(n < 1)
		return -1;

	push(destiny,origin);
	while (origin->last > - 1 && n > 1)
	{
		push(destiny,origin);
		cont++;
		if(destiny->stack[0] > destiny->stack[1])
		{
			swap(destiny);
			cont++;
		}
		n--;
	}
	return cont;
}



//int rot_or_rev()


void rotoswap(my_stack *a, int ciclos)
{

	while (ciclos > 0)
	{
	
	
	
		if(abs(abs(a->stack[0]) - abs(a->stack[1])) > abs(abs(a->stack[2]) - abs(a->stack[0])))
			swap(a);
		rotate(a);




		ciclos--;
	}
}



int ft_media(my_stack *a)
{
	return((ft_max(a)-ft_min(a))/a->last + 1);
}


void pasa_media(my_stack *a, my_stack *b)
{
	int media;

	media = ft_media(a);

	while(a->last - 1 > a->size / 2)
	{
		if(a->stack[0] > media)
			push(b,a);
		else
			rotate(a);
	}
}