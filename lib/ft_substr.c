/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:46:27 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/28 21:50:10 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_substr(char const *s, unsigned int start, unsigned long len)
{
	char	*ptr;
	char	*ptr0;

	if (ft_strlen(s) <= start || !s)
	{
		ptr = (char *)malloc(1 * sizeof(char));
		if (!ptr)
			return (0);
		*ptr = '\0';
		return (ptr);
	}
	else
	{
		if(start + (unsigned long)len < ft_strlen(s))
		{
		ptr = (char *)malloc((len + 1) * sizeof(char));
		if (!ptr)
			return (0);
		ptr0 = ptr;
		while (*s != '\0' && len-- > 0)
		{
			*ptr = *(s + start);
			ptr++;
			s++;
		}
		*ptr = '\0';
		return (ptr0);
		}
		else 
		{
		printf("%zd",(ft_strlen(s)+1 - (start)) * sizeof(char));
		ptr = (char *)malloc((ft_strlen(s) - (start + 1)) * sizeof(char));
		if (!ptr)
			return (0);
		ptr0 = ptr;
		while (*s != '\0' && len-- > 0)
		{
			*ptr = *(s + start);
			ptr++;
			s++;
		}
		*ptr = '\0';
		return (ptr0);
		}
	}
}
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (len > len_s - start)
		len = len_s - start;
	if (start < ft_strlen(s))
	{
		sub_str = (char *)malloc((len + 1) * sizeof(char));
		if (sub_str == NULL)
			return (NULL);
		ft_strlcpy(sub_str, s + start, len + 1);
	}
	else
	{
		sub_str = (char *)malloc(1 * sizeof(char));
		if (sub_str == NULL)
			return (NULL);
		sub_str[0] = '\0';
	}
	return (sub_str);
}
