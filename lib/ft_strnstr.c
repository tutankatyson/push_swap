/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:57:34 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/30 18:00:09 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Busca la cadena terminada '\0' needle en los len primeros 
**	caracteres de la cadena haystack
*/

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			match;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack) || len < ft_strlen(needle))
		return (0);
	while (i < len && haystack[i] != '\0' && (len - i) >= ft_strlen(needle))
	{
		match = 1;
		j = 0;
		while (j < ft_strlen(needle) && match)
		{
			if (haystack[i + j] != needle[j])
				match = 0;
			j++;
		}
		if (j == ft_strlen(needle) && match)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
