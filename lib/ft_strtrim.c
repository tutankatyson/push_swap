/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:12:57 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/28 21:49:54 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischrstr(char c, const char *str)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*ptr;

	if (s1[0] == '\0')
	{
		ptr = (char *)malloc(sizeof(char));
		*ptr = '\0';
		return (ptr);
	}
	start = 0;
	while (ft_ischrstr(s1[start], set) && start < (unsigned int)ft_strlen(s1))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_ischrstr(s1[end], set) && end > 0)
		end--;
	ptr = ft_substr(s1, start, end + 1 - start);
	return (ptr);
}
