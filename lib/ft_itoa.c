/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:20:43 by jorsanch          #+#    #+#             */
/*   Updated: 2022/09/28 21:44:31 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtab(char *str)
{
	char	temp;
	int		len;
	int		i;

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

static int	ft_counter(int n)
{
	int		count;
	int		res;

	res = n;
	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (res != 0)
	{
		res = res / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa_negative(int n, int count, char *str)
{
	int	i;

	if (n == 0)
		str[0] = '0';
	i = 0;
	if (n < 0)
	{
		str[count - 1] = '-';
		str[i] = (n % 10) * (-1) + '0';
		n = n / -10;
		i++;
		count--;
	}
	while (i < count && n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}	
	str = ft_strtab(str);
	return (str);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;
	int		i;

	count = ft_counter(n);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (n <= 0)
		return (ft_itoa_negative(n, count, str));
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
