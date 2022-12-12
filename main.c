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

#include <stdio.h>

#define STACK_SIZE 12

void sa(int *a);

static int cont = 0;

typedef struct mi_stack
{
	int		size;
	int     last;
    int     stack[STACK_SIZE];
}					my_stack;


int main(int argc, char **argv)
{

    int a[STACK_SIZE];
  //  int b[STACK_SIZE];

    /*inicializar*/

    if(argc == 1 || !argv)
        printf("\nERROR");

    printf("\nINPUT:%s",argv[1]);
    printf("\nARG_C:%i",argc);

    
    printf("\n%i,%i,%i",a[0],a[1],a[2]);
    
    sa(a);




    printf("\n%i,%i,%i",a[0],a[1],a[2]);


}

/*swap a*/

void sa(int *a)
{
    int temp;

    temp = a[0];
    a[0] = a[1];
    a[1] = temp;

    printf("sa");
    cont++;
}

/*rotate a*/

/*
void ra(int *a)
{
    int temp;

    

    printf("ra");
    cont++;
}
*/