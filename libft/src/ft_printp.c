/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:37:29 by tlamart           #+#    #+#             */
/*   Updated: 2019/02/09 14:59:17 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static size_t	nblen(long nb)
{
	size_t	size;

	if (nb == 0)
		return (1);
	size = 0;
	while (nb != 0)
	{
		size++;
		nb /= 16;
	}
	return (size);
}

static char		*filladdr(char *addr, long nb, int size)
{
	char	fill;

	addr = ft_strcpy(addr, "0x");
	while (size >= 2)
	{
		fill = nb % 16;
		if (fill < 10)
			fill += '0';
		else
			fill += 'a' - 10;
		addr[size] = fill;
		size--;
		nb /= 16;
	}
	return (addr);
}

static char		*pprint(void *ptr)
{
	size_t	size;
	char	*addr;

	if (!ptr)
		return (ft_strdup("0x0"));
	size = nblen((long)ptr) + 2;
	if (!(addr = ft_strnew(size)))
		return (NULL);
	addr = filladdr(addr, (long)ptr, (int)size - 1);
	return (addr);
}

int				ft_printp(va_list ap, char *opt)
{
	char	*ptr;
	int		width;
	int		precision;
	int		ret;

	pf_findwidth_n_precision(opt, &width, &precision);
	if (!(ptr = pprint(va_arg(ap, void*))))
		return (0);
	ret = ft_strlen(ptr);
	ret = pf_print(ptr, ret, width, opt);
	ft_strdel(&ptr);
	return (ret);
}
