/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:27:33 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/30 18:39:57 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************

Parámetros 					lst: 		la dirección de un puntero a un nodo.
							del: 		un puntero a función utilizado para 
										eliminar el contenido de un nodo.

Valor devuelto 				Nada

Funciones autorizadas		free

Descripción 				Elimina y libera el nodo ’lst’ dado y todos los
							consecutivos de ese nodo, utilizando la función
							’del’ y free(3).
							Al final, el puntero a la lista debe ser NULL.
*****************************************************************************/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
