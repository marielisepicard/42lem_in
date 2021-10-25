/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:43:47 by tlamart           #+#    #+#             */
/*   Updated: 2019/02/09 14:59:58 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	nblen(unsigned long long n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static char		*fillprint(unsigned long long n, char *nbr, int size)
{
	while (size >= 0)
	{
		nbr[size] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (nbr);
}

static char		*uprint(unsigned long long n, int precision)
{
	size_t	size;
	char	*nbr;

	if (n == 0 && precision == 0)
		return (ft_strdup(""));
	size = nblen(n);
	if (size < (unsigned int)precision)
		size = precision;
	if (!(nbr = ft_strnew(size)))
		return (NULL);
	nbr = fillprint(n, nbr, (int)(size - 1));
	return (nbr);
}

int				ft_printu(va_list ap, char *opt)
{
	char	*nbr;
	int		width;
	int		precision;
	int		ret;

	pf_findwidth_n_precision(opt, &width, &precision);
	if (!(nbr = uprint(va_arg(ap, unsigned long long), precision)))
		return (-1);
	ret = ft_strlen(nbr);
	ret = pf_print(nbr, ret, width, opt);
	ft_strdel(&nbr);
	return (ret);
}
