/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:47:21 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/03 13:15:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtab(char *str)
{
	char	temp;
	unsigned int		len;
	unsigned int		i;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		temp = str [i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}

static unsigned int	ft_counter(unsigned int n)
{
	unsigned int		count;
	unsigned int		res;

	res = n;
	if (n == 0)
		return (1);
	count = 0;
	while (res != 0)
	{
		res = res / 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int		count;
	char	*str;
	unsigned int		i;

	if(n == 0)
		return(ft_strdup("0"));
	count = ft_counter(n);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count] = '\0';
	i = 0;
	while (i < count && n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}	
	str = ft_strtab(str);
	return (str);
}
