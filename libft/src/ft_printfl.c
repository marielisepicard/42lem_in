/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 09:20:52 by tlamart           #+#    #+#             */
/*   Updated: 2019/02/09 14:58:57 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	nblen(double n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	if (n < 1)
		return (size + 1);
	while (n >= 1)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static int		sign(char **nbr, double *n, char *opt, int *size)
{
	char	*str;
	int		i;

	str = *nbr;
	i = 0;
	if (*n < 0)
	{
		str[i] = '-';
		(*size)--;
		i++;
		*n *= -1;
	}
	else if (ft_strchr(opt, ' ') || ft_strchr(opt, '+'))
	{
		if (ft_strchr(opt, ' '))
			str[i] = ' ';
		if (ft_strchr(opt, '+'))
			str[i] = '+';
		(*size)--;
		i++;
	}
	return (i);
}

static char		*fillprint(char *nbr, double n, int size, char *opt)
{
	double	aine;
	int		i;
	char	c;

	aine = 1;
	i = sign(&nbr, &n, opt, &size);
	while (aine * 10 < n)
		aine *= 10;
	while (size)
	{
		if (aine == 0.1)
		{
			nbr[i] = '.';
			i++;
		}
		c = n / aine;
		nbr[i] = c + '0';
		n -= (c * aine);
		aine /= 10;
		i++;
		size--;
	}
	return (nbr);
}

static char		*flprint(double n, int precision, char *opt)
{
	size_t	size;
	char	*nbr;

	if (n == 0 && precision == 0)
		return (ft_strdup(""));
	size = nblen(n);
	if (precision)
		size += precision + 1;
	if (!(nbr = ft_strnew(size)))
		return (NULL);
	nbr = fillprint(nbr, n, (int)(size - 1), opt);
	return (nbr);
}

int				ft_printfl(va_list ap, char *opt)
{
	char	*nbr;
	int		width;
	int		precision;
	int		ret;

	pf_findwidth_n_precision_fl(opt, &width, &precision);
	if (precision < 0)
		precision = 6;
	if (!(nbr = flprint(va_arg(ap, double), precision, opt)))
		return (-1);
	ret = ft_strlen(nbr);
	ret = pf_print(nbr, ret, width, opt);
	ft_strdel(&nbr);
	return (ret);
}
