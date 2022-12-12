/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:02:11 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/29 20:57:01 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr = dst;
	while (n > 0)
	{
		*(char *)ptr = *(char *)src;
		ptr++;
		src++;
		n--;
	}
	return (dst);
}
