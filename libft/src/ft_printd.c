/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:52:25 by tlamart           #+#    #+#             */
/*   Updated: 2019/02/09 14:58:32 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			ft_printd(va_list ap, char *opt)
{
	char	*nbr;
	int		width;
	int		precision;
	int		ret;

	pf_findwidth_n_precision(opt, &width, &precision);
	if (ft_strstr(opt, "ll"))
	{
		if (!(nbr = lltoprint(va_arg(ap, long), precision, opt)))
			return (-1);
	}
	else if (ft_strchr(opt, 'l'))
	{
		if (!(nbr = ltoprint(va_arg(ap, long long), precision, opt)))
			return (-1);
	}
	else if (!(nbr = itoprint(va_arg(ap, int), precision, opt)))
		return (-1);
	ret = ft_strlen(nbr);
	ret = pf_print(nbr, ret, width, opt);
	ft_strdel(&nbr);
	return (ret);
}
