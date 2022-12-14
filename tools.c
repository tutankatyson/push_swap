/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:11:33 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/14 17:16:50 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
//    printf("s%c\n",st->ch);
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
//    printf("r%c\n",st->ch);
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

//	printf("rr%c\n",st->ch);
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

//	printf("p%c\n",sta->ch);
	return 1;
}

