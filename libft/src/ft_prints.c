/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:28:25 by tlamart           #+#    #+#             */
/*   Updated: 2019/06/04 00:55:25 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_prints(va_list ap, char *opt)
{
	char	*str;
	int		width;
	int		precision;
	int		ret;

	pf_findwidth_n_precision(opt, &width, &precision);
	if (!(str = ft_strdup((va_arg(ap, char*)))))
		return (-1);
	if (ft_strchr(opt, '.'))
		str[precision] = '\0';
	ret = ft_strlen(str);
	ret = pf_print(str, ret, width, opt);
	ft_strdel(&str);
	return (ret);
}
