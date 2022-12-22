/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:11:33 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/22 21:07:05 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** * * * * * * T O O L S * * * * * * **/

int	ft_init(my_stack *stack,int argc,char **argv)
{
	/*INICIALIZAR*/
	
	stack->size		=	argc - 1;
	stack->stack	=	(int *)ft_calloc(sizeof(int) , (argc - 1));

	/*discriminar stacks*/

	if(argv == NULL){			//stack B
		stack->last			=	-1;
		stack->ch 			=	'b';
		stack->dispersión	=	0;
//		status(stack);
		return 1;
	
	/*Captar argumentos*/		//Stack A

	}else
	{
		stack->last			=	argc - 2;
		stack->ch 			= 	'a';
		stack->max			=	ft_max(stack);
		stack->min			=	ft_min(stack);
		stack->dispersión	=	((stack->max - stack->min / stack->size));
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

int swap_ordena(my_stack *st)
{
	if(st->last < 2)
		return 0;
	if(st->stack[1] < st->stack[0])
		return 1;
	return 0;
}

/** * * * * * * M A T H * * * * * * **/

int abs(int num)
{
	if(num < 0)
		return -num;
	return num;
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

int ft_find_min(my_stack *st)
{
	int i = 1;
	int temp = st->stack[0];
	int min = 0;

	while (i <= st->last)
	{
		if(temp > st->stack[i])
		{
			temp = st->stack[i];
			min = i;
		}
		i++;
	}
	if(min > st->size - min)
		min = min-st->size;
//	printf("\nMIN-->%iº",min);
	return min;
}

int ft_find_max(my_stack *st)
{
	int i = 1;
	int temp = st->stack[0];
	int max = 0;

	while (i <= st->last)
	{
		if(temp < st->stack[i])
		{
			temp = st->stack[i];
			max = i;
		}
		i++;
	}
	if(max > st->size - max)
		max = max-st->size;
//	printf("\nMAX-->%iº",max);
	return max;
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

void dispersion(my_stack *st)
{
	int i = 0;
	float juntos = 0;
	float juntos5 = 0;
	float juntos10 = 0;

	while(i < st->last)
	{
		if(abs(st->stack[i] - st->stack[i+1]) == 1 || abs(st->stack[i] - st->stack[i+2]) == 1 ||abs(st->stack[i] - st->stack[i+3]) == 1)
			juntos++;
		if(abs(st->stack[i] - st->stack[i+1]) < 5 || abs(st->stack[i] - st->stack[i+2]) < 5 ||abs(st->stack[i] - st->stack[i+3]) < 5)
			juntos5++;
		if(abs(st->stack[i] - st->stack[i+1]) < 10 || abs(st->stack[i] - st->stack[i+2]) < 10 ||abs(st->stack[i] - st->stack[i+3]) < 10)
			juntos10++;
		i++;
	}
	printf("\n------ STACK %c ------",st->ch);
	printf("\nELEMENTOS  :%i",st->last+1);

	printf("\nJuntos  :%f",juntos);
	printf("\nJuntos5 :%f",juntos5);
	printf("\nJuntos10:%f",juntos10);
	printf("\nDispersion  :%.3f",100*juntos/st->last);
	printf("\nDispersion5 :%3.f",100*juntos5/st->last);
	printf("\nDispersion10:%3.f",100*juntos10/st->last);
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
			printf("\n  -        |");
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

int checkp(my_stack *st)
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

/** * * * * B A S I C A S * * * * **/

/*swap*/

void ss(my_stack *sta, my_stack *stb)
{
    int temp;

	if(sta->last > 1)
	{
    temp 			= 	sta->stack[0];
    sta->stack[0] 	= 	sta->stack[1];
    sta->stack[1] 	= 	temp;
	}
	if(stb->last > 1)
	{
    temp 			= 	stb->stack[0];
    stb->stack[0] 	= 	stb->stack[1];
    stb->stack[1] 	= 	temp;
	}
    printf("ss\n");
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
    printf("s%c\n",st->ch);
}

/*rotate*/

void rr(my_stack *sta, my_stack *stb)
{
    int i = 1;
	int temp;
	
	if(sta->last > 0)
	{
		temp = sta->stack[0];

		while (i <= sta->last)
		{
			sta->stack[i - 1] = sta->stack[i];
			i++;
		}
		sta->stack[i - 1] = temp;
	}
	i = 1;
	if(stb->last > 0)
	{
		temp = stb->stack[0];

		while (i <= stb->last)
		{
			stb->stack[i - 1] = stb->stack[i];
			i++;
		}
		stb->stack[i - 1] = temp;
	}


    printf("rr\n");
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
    printf("r%c\n",st->ch);
}

/*reverse*/

void rrr(my_stack *sta, my_stack *stb)
{
	int i = 0;
	int temp;

	temp = sta->stack[sta->last];

	while (i < sta->last)
	{
		sta->stack[sta->last-i] = sta->stack[sta->last-i-1];
		i++;
	}
	sta->stack[0] = temp;

	i = 0;
	temp = stb->stack[stb->last];
	while (i < stb->last)
	{
		stb->stack[stb->last-i] = stb->stack[stb->last-i-1];
		i++;
	}
	stb->stack[0] = temp;

	printf("rrr\n");
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

	printf("rr%c\n",st->ch);
}

/*push*/
int push(my_stack *to, my_stack *from)
{
	if(from->last == -1)
		return 0;
	int i = 0;

	while (i <= to->last)
	{
		to->stack[to->last - i+1] = to->stack[to->last - i];
		i++;
	}
	to->stack[0] = from->stack[0];
	to->last++;
	i = 0;
	while (i < from->last)
	{
		from->stack[i] = from->stack[i+1];
		i++;
	}
	from->last--;
	if(to->stack[0] > to->max)
		to->max = to->stack[0];
	if(to->stack[0] < to->min)
		to->min = to->stack[0];


	printf("p%c\n",to->ch);
	return 1;
}




