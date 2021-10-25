/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:23:30 by tlamart           #+#    #+#             */
/*   Updated: 2019/02/09 14:59:08 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	nblen(unsigned long long nb)
{
	size_t	size;

	if (nb == 0)
		return (1);
	size = 0;
	while (nb != 0)
	{
		size++;
		nb /= 8;
	}
	return (size);
}

static char		*fillprint(unsigned long long n, char *nb, int size)
{
	while (size >= 0)
	{
		nb[size] = n % 8 + '0';
		n /= 8;
		size--;
	}
	return (nb);
}

static char		*oprint(unsigned long long nb, int precision, char *opt)
{
	size_t	size;
	char	*nbr;

	if (nb == 0 && precision == 0)
		return (ft_strdup(""));
	size = nblen(nb);
	if (ft_strchr(opt, '#'))
		size++;
	if ((unsigned int)precision > size)
		size = precision;
	if (!(nbr = ft_strnew(size)))
		return (NULL);
	size--;
	nbr = fillprint(nb, nbr, size);
	return (nbr);
}

int				ft_printo(va_list ap, char *opt)
{
	char	*nbr;
	int		width;
	int		precision;
	int		ret;

	pf_findwidth_n_precision(opt, &width, &precision);
	if (!(nbr = oprint(va_arg(ap, unsigned long long), precision, opt)))
		return (-1);
	ret = ft_strlen(nbr);
	ret = pf_print(nbr, ret, width, opt);
	ft_strdel(&nbr);
	return (ret);
}
