/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:48:31 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/29 20:52:42 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	int			found;
	void		*ptr;

	i = 0;
	found = 0;
	ptr = 0;
	while (i < n && !found)
	{
		if ((unsigned char)c == *(unsigned char *)(s + i))
		{
			ptr = (void *)s + i;
			found = 1;
		}
		i++;
	}
	return (ptr);
}
