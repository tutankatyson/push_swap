/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:53:34 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/28 21:45:06 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	char			*ptr;

	ptr = b;
	ch = (unsigned char) c;
	while (len > 0)
	{
		*ptr = ch;
		ptr++;
		len--;
	}
	return (b);
}
