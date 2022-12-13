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


int main(int argc, char **argv)
{

	my_stack a, b;
	my_stack a1, b1;
	my_stack a2, b2;

	int cont = 0;

	/*Control de errores*/

    if(argc == 1 || !argv){
        printf("\nERROR");
		return 0;
	}

    /*inicializar*/
	
	ft_init(&a, argc, argv);
	ft_init(&b, argc, NULL);
	ft_init(&a1, argc, argv);
	ft_init(&b1, argc, NULL);
	ft_init(&a2, argc, argv);
	ft_init(&b2, argc, NULL);


//	cont = cont + rollup_b_pushall_2(&a1,&b1);



//	push(&b,&a);

//	print(&a,&b);
//	print(&a1,&b1);
//	printf(GREEN"ORDER"RESET);


//	print(&a,&b);

	cont = cont + rollup_b_pushall(&a,&b);
	cont = cont + rollup_b_pushall_2(&a1,&b1);
	PUSH_SWAP(&a2,&b2);


//	print(&a,&b);
//	print(&a1,&b1);


//	print(&a1,&b1);







	checkp(&a);


	printf("\nCONTADOR: %i  SOBRE: %i",cont,argc-1);

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

	cont = cont + algoritmo2_1(a,b);
	cont = cont + push_all(a,b);

	checkp(a);
	printf(YELLOW"\n - rollup_b_pushall_2 - ");
	printf("CONTADOR: %i "RESET,cont);

	return cont;
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
			checkp(a);
			printf(YELLOW"\n - PUSH_SWAP - ");
			printf("CONTADOR: %i "RESET,cont);
			return cont;
		}

		if(cont > 10000)
			end = 1;
	}
	
	return 0;

}

int one_stack(my_stack *a, my_stack *b)
{
	int cont = 0;
	int end = 0;

	while (!end)
	{
		if()
		
		



	}
	

	checkp(a);
	printf(YELLOW"\n - PUSH_SWAP - ");
	printf("CONTADOR: %i "RESET,cont);
	return 0;

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
	int cont = 0;
	int max;
	int min;

	max = ft_max(sta);
	min = ft_min(sta);

	while (sta->last >= 0)
	{
		if(sta->stack[0] == min)
		{
			push(stb,sta);
			cont++;
			min = ft_min(sta);
		}
		else if(sta->stack[0] == max)
		{
			push(stb,sta);
			if(stb->last > 1)
				rotate(stb);
			cont = cont + 2;
			max = ft_max(sta);
		}else
		{
			rotate(sta);
			cont++;
		}
	}
	while (stb->stack[0] < stb->stack[stb->last])
	{
		rotate(stb);
	}
	
	//print(sta,stb);
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

/** * * * * * * T O O L S * * * * * * **/

int	ft_init(my_stack *stack,int argc,char **argv)
{
	/*INICIALIZAR*/
	
	stack->size		=	argc - 1;
	stack->stack	=	(int *)ft_calloc(sizeof(int) , (argc - 1));

	/*discriminar stacks*/

	if(argv == NULL){			//stack B
		stack->last		=	-1;
		stack->ch 		=	'b';
//		status(stack);
		return 1;
	
	/*Captar argumentos*/		//Stack A

	}else
	{
		stack->last		=	argc - 2;
		stack->ch 		= 	'a';
		int i = 1;
		while (i < argc)
		{
			stack->stack[i-1] = ft_atoi(argv[i]);
			i++;
		}
//		status(stack);
		return 0;
	}

}

int ft_max(my_stack *st)
{
	int i = 1;
	int temp = st->stack[0];

	while (i <= st->last)
	{
		if(temp < st->stack[i])
			temp = st->stack[i];
		i++;
	}

//	printf("\nMAX-->%i",temp);
	return temp;
}

int ft_min(my_stack *st)
{
	int i = 1;
	int temp = st->stack[0];

	while (i <= st->last)
	{
		if(temp > st->stack[i])
			temp = st->stack[i];
		i++;
	}

//	printf("\nMIN-->%i",temp);
	return temp;
}

int	ft_isrevorder(my_stack *st)
{
	int i = 0;
	int step = 0;

	if(st->stack[st->last] < st->stack[0] && step == 0)
		step++;

	while (i < st->last)
	{
		if(st->stack[i] < st->stack[i+1] && step == 0)
			step++;
		else 
			if(st->stack[i] < st->stack[i+1] && step != 0)
				return 0;
		i++;
	}
	return 1;
}

int	ft_isorder(my_stack *st)
{
	int i = 0;
	int step = 0;

	if(st->stack[st->last] > st->stack[0] && step == 0)
		step++;

	while (i < st->last)
	{
		if(st->stack[i] > st->stack[i+1] && step == 0)
			step++;
		else 
			if(st->stack[i] > st->stack[i+1] && step != 0)
				return 0;
		i++;
	}
	return 1;
}

int check(my_stack *st)
{
	int i = 1;

	while (i < st->size)
	{
		if(!(st->stack[i-1] < st->stack[i]))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

