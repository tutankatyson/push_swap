/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:40:59 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/03 13:10:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_args(long int n, char *base)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (i < ft_strlen(base))
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (n == 0)
		return (2);
	return (1);
}

static void	ft_do_all(long int n, char *base)
{
	char	c;
	int		nbase;

	nbase = ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		ft_do_all((n / nbase) * (-1), base);
	}
	if (n > 0)
		ft_do_all(n / nbase, base);
	if (n != 0)
	{
		if (n < 0)
			n = n * (-1);
		c = base[n % nbase];
		write(1, &c, 1);
	}
}

int	ft_putnbrbase(long int n, char *base)
{
	int cont;
	int div;

	cont = 0;
	if (ft_check_args(n, base) == 1)
		ft_do_all(n, base);
	if (ft_check_args(n, base) == 2)
		write(1, base, 1);
	
	div = ft_strlen(base);
	while (n / div > 0)
	{
		cont++;
		n = n / div;
	}
	return (cont-1);
}