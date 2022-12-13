/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:13:40 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/13 21:16:47 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "push_swap.h"

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
int	ft_isorder(my_stack *st);
int	ft_isrevorder(my_stack *st);

int check(my_stack *st);
int checkp(my_stack *st);
int print(my_stack *a, my_stack *b);
void status(my_stack *st);

int algoritmo1(my_stack *sta, my_stack *stb);
int algoritmo1_1(my_stack *sta, my_stack *stb);
int algoritmo2(my_stack *sta, my_stack *stb);
int algoritmo2_1(my_stack *sta, my_stack *stb);
int ordena3(my_stack *st);
int push_all(my_stack *sta, my_stack *stb);


int rollup_b_pushall(my_stack *a, my_stack *b);
int rollup_b_pushall_2(my_stack *a, my_stack *b);



#endif