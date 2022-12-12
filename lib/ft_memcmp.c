/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:11:50 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/28 21:45:00 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n > 0)
	{
		while (n > 0)
		{
			if (*(unsigned char *)s1 == *(unsigned char *)s2)
			{
			s1++;
			s2++;
			n--;
			}
			else
				return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
	}
	return (0);
}
