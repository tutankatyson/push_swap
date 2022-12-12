/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:15:03 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/30 18:40:02 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************************************************

Parámetros 				lst: 		el nodo a liberar.
						del: 		un puntero a la función utilizada para 
									liberar el contenido del nodo.
Valor devuelto			Nada

Funciones autorizadas	free

Descripción 			Toma como parámetro un nodo ’lst’ y libera la
						memoria del contenido utilizando la función ’del’
						dada como parámetro, además de liberar el nodo. La
						memoria de ’next’ no debe liberarse.

******************************************************************************/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
