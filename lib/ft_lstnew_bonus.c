/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:45:21 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/30 18:40:19 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/***************************************************************************

Parámetros 				content: 	El contenido con el que crear el nodo.

Valor devuelto 			El nuevo nodo

Funciones autorizadas	malloc

Descripción 			Crea un nuevo nodo utilizando malloc(3). La
						variable miembro ’content’ se inicializa con el
						contenido del parámetro ’content’. La variable
						’next’, con NULL.

**************************************************************************/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
