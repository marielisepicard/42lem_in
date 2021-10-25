/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:09:04 by tlamart           #+#    #+#             */
/*   Updated: 2019/02/09 14:58:16 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_printc(va_list ap, char *opt)
{
	int		width;
	int		precision;
	int		ret;

	pf_findwidth_n_precision(opt, &width, &precision);
	if (width)
		ret = width;
	else
		ret = 1;
	if (!ft_strchr(opt, '-'))
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
	}
	ft_putchar(va_arg(ap, int));
	while (width > 1)
	{
		ft_putchar(' ');
		width--;
	}
	return (ret);
}
