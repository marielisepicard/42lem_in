/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:26:44 by tlamart           #+#    #+#             */
/*   Updated: 2019/02/09 15:00:47 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static size_t	nblen(int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	if (n < 0)
		size = 1;
	else
		size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void		fillprint(int n, char **nbr, int size, char *opt)
{
	char	*print;

	print = *nbr;
	if (n < 0)
	{
		print[0] = '-';
		print[size] = n % 10 * (-1) + '0';
		size--;
		n /= -10;
	}
	while (size >= 0 && print[size] != '-')
	{
		print[size] = n % 10 + '0';
		n /= 10;
		size--;
	}
	if (*print != '-')
	{
		if (ft_strchr(opt, ' '))
			print[0] = ' ';
		else if (ft_strchr(opt, '+'))
			print[0] = '+';
	}
}

char			*itoprint(int n, int precision, char *opt)
{
	char	*print;
	size_t	size;

	if (n == 0 && precision == 0)
		return (ft_strdup(""));
	size = nblen(n);
	precision -= size;
	if (n < 0)
		precision++;
	if (precision > 0)
		size += precision;
	if (n >= 0 && (ft_strchr(opt, ' ') || ft_strchr(opt, '+')))
		size++;
	if (!(print = ft_strnew(size)))
		return (NULL);
	size--;
	fillprint(n, &print, size, opt);
	return (print);
}
