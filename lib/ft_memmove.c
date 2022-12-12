/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:10:27 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/30 18:26:04 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dst0;

	dst0 = dst;
	if (dst < src)
	{
		while (len-- > 0)
		{
			*(char *)dst = *(char *)src;
			dst++;
			src++;
		}
	}
	else if (dst > src)
	{
		dst = dst + len;
		src = src + len;
		while (len-- > 0)
		{
			dst--;
			src--;
			*(char *)dst = *(char *)src;
		}
	}
	return (dst0);
}
