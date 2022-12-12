/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:36:11 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/28 21:49:48 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*ret;

	ret = NULL;
	ptr = (char *)s;
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
			ret = ptr;
		ptr++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (ret);
}
