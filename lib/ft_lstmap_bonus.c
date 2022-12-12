/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:20:52 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/30 18:40:14 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
Parámetros 				lst:	un puntero a un nodo.

						f:		la dirección de un puntero a una función usada
								en la iteración de cada elemento de la lista.

						del:	un puntero a función utilizado para eliminar
								el contenido de un nodo, si es necesario.

Valor devuelto 			La nueva lista.

						NULL si falla la reserva de memoria.

Funciones autorizadas	malloc, free

Descripción 			Itera la lista ’lst’ y aplica la función ’f’ al
						contenido de cada nodo. Crea una lista resultante
						de la aplicación correcta y sucesiva de la función
						’f’ sobre cada nodo. La función ’del’ se utiliza
						para eliminar el contenido de un nodo, si hace
						falta.
*****************************************************************************/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))

{
	t_list	*node;
	t_list	*start;

	start = NULL;
	while (lst)
	{
		node = ft_lstnew((f)(lst->content));
		if (!node)
		{
			ft_lstclear(&start, del);
		}
		ft_lstadd_back(&start, node);
		lst = lst->next;
	}
	return (start);
}
