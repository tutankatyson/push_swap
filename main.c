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

#include "libft.h"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


typedef struct mi_stack
{
	int		size;
	int     last;
    int     *stack;
	char	ch;
}					my_stack;

void swap(my_stack *st);
void rotate(my_stack *st);
void reverse(my_stack *st);
void ss(my_stack *sta, my_stack *stb);
void rr(my_stack *sta, my_stack *stb);
void rrr(my_stack *sta, my_stack *stb);
int push(my_stack *sta, my_stack *stb);

int	ft_init(my_stack *stack,int argc,char **argv);

int ft_max(my_stack *st);
int ft_min(my_stack *st);

int check(my_stack *st);
int print(my_stack *a, my_stack *b);
void status(my_stack *st);

int algoritmo1(my_stack *sta, my_stack *stb);
int algoritmo2(my_stack *sta, my_stack *stb);
int push_all(my_stack *sta, my_stack *stb);




int main(int argc, char **argv)
{

	my_stack a, b;
	int cont = 0;

	/*Control de errores*/

    if(argc == 1 || !argv){
        printf("\nERROR");
		return 0;
	}

    /*inicializar*/
	
	ft_init(&a, argc, argv);
	ft_init(&b, argc, NULL);


//	push(&b,&a);

//	print(&a,&b);

//	ft_max(&a);
//	ft_min(&a);
	print(&a,&b);
	cont += algoritmo2(&a,&b);
	cont += push_all(&b,&a);
	print(&a,&b);

	check(&a);
	printf("\nCONTADOR: %i  SOBRE: %i",cont,argc-1);

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

int push_all(my_stack *sta, my_stack *stb)
{
	int cont = 0;

	while (sta->last >= 0)
	{
		push(stb,sta);
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
		stack->ch 		=	'B';
		status(stack);
		return 1;
	
	/*Captar argumentos*/		//Stack A

	}else
	{
		stack->last		=	argc - 2;
		stack->ch 		= 	'A';
		int i = 1;
		while (i < argc)
		{
			stack->stack[i-1] = ft_atoi(argv[i]);
			i++;
		}
		status(stack);
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

/** * * * * M o n i t o r e o * * * * **/

int print(my_stack *a, my_stack *b)
{
	int i = 0;
	
	printf("\n--STACK A--|--STACK B--");
	
	while (i < a->size)
	{
		if(i <= a->last)
			printf("\n  %-9i|",a->stack[i]);
		else
			printf("\n  -      |");
		if(i <= b->last)
			printf("   %-6i",b->stack[i]);
		else
			printf("   -   ");

		i++;
	}
	return 0;
	
}

void status(my_stack *st)
{
	printf("\n --STACK %c--",st->ch);
	printf("\n --SIZE : %i",st->size);
	printf("\n --LAST : %i",st->last);
}

int check(my_stack *st)
{
	int i = 1;

	while (i < st->size)
	{
		if(!(st->stack[i-1] < st->stack[i]))
		{
			printf(RED"\n check error"RESET);
			return 0;
		}
		i++;
	}
	printf(GREEN"\n check OK"RESET);
	return 1;
}

/*swap*/

void ss(my_stack *sta, my_stack *stb)
{
	swap(sta);
	swap(stb);
}

void swap(my_stack *st)
{
    int temp;

	if(st->last > 1)
	{
    temp 			= 	st->stack[0];
    st->stack[0] 	= 	st->stack[1];
    st->stack[1] 	= 	temp;
	}
    printf("\n-- - - > S %c < - - --",st->ch);
}

/*rotate*/

void rr(my_stack *sta, my_stack *stb)
{
	rotate(sta);
	rotate(stb);
}

void rotate(my_stack *st)
{
    int i = 1;
	int temp;
	
//	status(st);

	if(st->last > 0)
	{
		temp = st->stack[0];

		while (i <= st->last)
		{
			st->stack[i - 1] = st->stack[i];
			i++;
		}
		st->stack[i - 1] = temp;
	}
    printf("\n-- - - > R %c < - - --",st->ch);
}

/*reverse*/

void rrr(my_stack *sta, my_stack *stb)
{
	reverse(sta);
	reverse(stb);
}

void reverse(my_stack *st)
{
	int i = 0;
	int temp;

	temp = st->stack[st->last];

	while (i < st->last)
	{
		st->stack[st->last-i] = st->stack[st->last-i-1];
		i++;
	}
	st->stack[0] = temp;

    printf("\n-- - - > R R %c < - - --",st->ch);
}

/*push*/

int push(my_stack *sta, my_stack *stb)
{
	if(stb->last == -1)
		return 0;
	int i = 0;

	while (i <= sta->last)
	{
		sta->stack[sta->last - i+1] = sta->stack[sta->last - i];
		i++;
	}
	sta->stack[0] = stb->stack[0];
	sta->last++;
	i = 0;
	while (i < stb->last)
	{
		stb->stack[i] = stb->stack[i+1];
		i++;
	}
	stb->last--;

	printf("\n-- - - > P %c < - - --",sta->ch);
	return 1;
}