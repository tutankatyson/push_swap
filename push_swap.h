/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:13:40 by jorsanch          #+#    #+#             */
/*   Updated: 2023/01/03 18:54:35 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

/*********COLORES**********/

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

/********ESTRUCTURAS*******/

typedef struct mi_stack
{
    int     *stack;
	int		*order;
	char	ch;
	int		size;
	int     last;

	int 	max;
	int 	min;
	int 	dispersión;

}					my_stack;


void rotoswap(my_stack *a, int ciclos);



/********OPERACIONES*******/

void swap(my_stack *st);
void rotate(my_stack *st);
void reverse(my_stack *st);
void ss(my_stack *sta, my_stack *stb);
void rr(my_stack *sta, my_stack *stb);
void rrr(my_stack *sta, my_stack *stb);
int push(my_stack *to, my_stack *from);

/********TOOLS*******/

void	ft_init(my_stack *stack,int argc,char **argv);
void ft_index(my_stack *st);
int ft_max(my_stack *st);
int ft_min(my_stack *st);
int ft_find_max(my_stack *st);
int ft_find_min(my_stack *st);
int	ft_isorder(my_stack *st);
int	ft_isrevorder(my_stack *st);
int check(my_stack *st);
int abs(int num);
void dispersion(my_stack *st);


/********MONITOR*******/

int checkp(my_stack *st);
int print(my_stack *a, my_stack *b);
void status(my_stack *st);

/********BASIC ALGORHIMS*******/

int algoritmo1(my_stack *sta, my_stack *stb);
int algoritmo1_1(my_stack *sta, my_stack *stb);
int algoritmo2(my_stack *sta, my_stack *stb);
int algoritmo2_1(my_stack *sta, my_stack *stb);
int algoritmo2_2(my_stack *sta, my_stack *stb);
int ordena3(my_stack *st);
int push_all(my_stack *sta, my_stack *stb);
int p_s(my_stack *a, my_stack *b);
int push_swap_up(my_stack *a, my_stack *b);
int push_swap_down(my_stack *a, my_stack *b);
int ps_all_up(my_stack *a, my_stack *b);
int ps_all_down(my_stack *a, my_stack *b);
int swap_ordena(my_stack *st);
int push_swap_n_down(int n, my_stack *origin, my_stack *destiny);
int dealer(int n, my_stack *a, my_stack *b);

/********FULL ALGORHIMS*******/

int rollup_b_pushall(my_stack *a, my_stack *b);
int rollup_b_pushall_2(my_stack *a, my_stack *b);
int rollup_b_pushall_3(my_stack *a, my_stack *b);
int PUSH_SWAP(my_stack *a, my_stack *b);


#endif

/****** ** ** * * * C O M B I N A T O R I A   D E   3 * * * ** ** *******************

123..
132..				<s>		32..1	23..1	123..
213..				s		123..
231..				<s>s	31..2	13..2	213..	123..
312..				s<s>	132..	32..1	23..1	123..
321..				s<s>s	231..	31..2	13..2	213..	123..



****** ** ** * * * C O M B I N A T O R I A   D E   4 * * * ** ** *******************
		<		>		s
1234	2341 	4123	2134		OK	     º1	  º2   º3	º4   º5   º6    º7    
1243								>>s>> 	2341 3412 4312 3124 1234
1324								<s>		3241 2341 1234
1342								>s		2134 1234
1423								s<		4123 1234
1432								s>>s> 	4132 1324 3241 2341 1234
------------------------------------------------------------------------------------
2134	1342	4213	X			s		1234
2143	1432	3214	1243		s>>s>>	1243 2341 4312 3412 4123 1234
2314								>>s<	4231 1423 4123 1234 	
2341	3412	X		3241		>		1234
2413								>s>		3241 2341 1234
2431								<s>>	4312 3412 2341 1234
------------------------------------------------------------------------------------
3124								>s>>	4312 3412 2341 1234
3142								s>s		1342 2134 1234
3214					2314		<s>>s>>	2143 1243 2431 4312 3412 4123 1234
3241								s<		2341 1234
3412								>> 		2341 1234
3421								>>s		1342 2134 1234
------------------------------------------------------------------------------------
4123	X		3412	1423		<		1234
4132								>>s>	1324 3241 2341 1234
4213								<s		2134 1234
4231								>s<		1423 4123 1234
4312								>> 		3124 1234
4321								>s>>s>	1432 4132 1324 3241 2341 1234
------------------------------------------------------------------------------------

--- Ultimo termino ordenado

1234
2134		s			1234
1324		<s>			3241 2341 1234
2314		>>s<		4231 1423 4123 1234 	
3124		>s>>		4312 3412 2341 1234
3214	*	<s>s<s>		2143 1243 2431 4312 3412 4123 1234

		*Algoritmo ciclico


***** ** * * * * C O M B I N A T O R I A   D E   A L G O R I T M O S * * * * ** *****

Psp		(swap^2)	->> Equivale a un swap de 2º x 3º
PPspp	(swap^3)	->> Equivale a un swap de 3º x 4º





******* ** ** * * * C O M B I N A T O R I A   D E   5 * * * ** ** *******************

12345	>>>>	51234 45123 34512 23451		
12354	>>s<<	41235 54123 45123 51234 12345
12435
12453
12534
12543
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
13245
13254
13425
13452
13524
13542
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
14235
14253
14325
14352
14523
14532
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
15234
15243
15324
15342
15423
15432
---------------------------------------------------------------------------------------
31
31
32
32
34
34
35
35

41
41
42
42
43
43
45
45

51
51
52
52
53
53
54
54

*/
