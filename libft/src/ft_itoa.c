/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:07:04 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/20 17:11:15 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size += 2;
		n /= -10;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char		*ft_printnb(int n, char *str, size_t size)
{
	size--;
	if (n < 0)
	{
		str[0] = '-';
		if (n < -9)
			str[size] = (-n - 10) % 10 + '0';
		else
			str[size] = -n % 10 + '0';
		n /= -10;
		size--;
	}
	while (n > 0)
	{
		str[size] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = ft_nbrlen(n);
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	str = ft_printnb(n, str, size);
	return (str);
}
