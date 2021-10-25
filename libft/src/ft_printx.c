/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:50:45 by tlamart           #+#    #+#             */
/*   Updated: 2019/02/09 15:00:28 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	nblen(unsigned long long n)
{
	size_t size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		size++;
		n /= 16;
	}
	return (size);
}

static char		*fillprint(char *nb, unsigned long long n, int size, char *opt)
{
	char	fill;

	if (ft_strchr(opt, '#') && n != 0)
		nb = ft_strcpy(nb, "0x");
	while (size >= 0 && nb[size] != 'x')
	{
		fill = n % 16;
		if (fill < 10)
			fill += '0';
		else
			fill += 'a' - 10;
		nb[size] = fill;
		size--;
		n /= 16;
	}
	return (nb);
}

static char		*xprint(unsigned long long n, int precision, char *opt)
{
	size_t	size;
	char	*nbr;

	if (n == 0 && precision == 0)
		return (ft_strdup(""));
	size = nblen(n);
	if ((unsigned int)precision > size)
		size = precision;
	if (ft_strchr(opt, '#') && n != 0)
		size += 2;
	if (!(nbr = ft_strnew(size)))
		return (NULL);
	nbr = fillprint(nbr, n, size - 1, opt);
	return (nbr);
}

int				ft_printx(va_list ap, char *opt)
{
	char	*nbr;
	int		width;
	int		precision;
	int		ret;

	pf_findwidth_n_precision(opt, &width, &precision);
	if (!(nbr = (xprint(va_arg(ap, unsigned long long), precision, opt))))
		return (-1);
	ret = ft_strlen(nbr);
	ret = pf_print(nbr, ret, width, opt);
	ft_strdel(&nbr);
	return (ret);
}

int				ft_printxm(va_list ap, char *opt)
{
	char	*nbr;
	int		width;
	int		precision;
	int		ret;
	int		i;

	pf_findwidth_n_precision(opt, &width, &precision);
	if (!(nbr = (xprint(va_arg(ap, unsigned long long), precision, opt))))
		return (-1);
	i = 0;
	while (nbr[i])
	{
		if ('a' <= nbr[i] && nbr[i] <= 'z')
			nbr[i] -= 32;
		i++;
	}
	ret = ft_strlen(nbr);
	ret = pf_print(nbr, ret, width, opt);
	ft_strdel(&nbr);
	return (ret);
}
