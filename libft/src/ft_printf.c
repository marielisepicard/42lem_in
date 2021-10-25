/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:33:03 by tlamart           #+#    #+#             */
/*   Updated: 2019/06/04 00:55:00 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

t_printf		g_fcttab[10] =
{
	{'d', &ft_printd},
	{'i', &ft_printd},
	{'o', &ft_printo},
	{'u', &ft_printu},
	{'x', &ft_printx},
	{'X', &ft_printxm},
	{'f', &ft_printfl},
	{'p', &ft_printp},
	{'c', &ft_printc},
	{'s', &ft_prints},
};

static char	*opt(char **str)
{
	const char	*begin;

	begin = *str;
	(*str)++;
	while (**str != 'd' && **str != 'i' && **str != 's' && **str != 'o'
	&& **str != 'u' && **str != 'x' && **str != 'X' && **str != 'f'
	&& **str != 'p' && **str != 'c' && **str != '%' && **str)
		(*str)++;
	if (!*str)
		return (NULL);
	(*str)++;
	return (ft_strsub(begin, 0, *str - begin));
}

static char	find_conv(char *str)
{
	while (*(str + 1))
		str++;
	return (*str);
}

static int	printconv(char *opt, va_list ap)
{
	int		ret;
	char	conv_spe;
	int		i;

	if (!opt)
		return (-1);
	conv_spe = find_conv(opt);
	i = 0;
	if (conv_spe == '%')
	{
		ft_putchar('%');
		ft_strdel(&opt);
		return (1);
	}
	while (g_fcttab[i].conv != conv_spe && i < 10)
		i++;
	if (i == 10)
		return (-1);
	ret = g_fcttab[i].printfct(ap, opt);
	ft_strdel(&opt);
	return (ret);
}

static int	printformat(char **format)
{
	int			ret;
	const char	*str;

	ret = 0;
	str = *format;
	while (str[ret] && str[ret] != '%')
		ret++;
	write(1, str, ret);
	*format += ret;
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		status;

	va_start(ap, format);
	ret = 0;
	while (format && *format)
	{
		if (*format == '%')
			status = printconv(opt((char**)&format), ap);
		else
			status = printformat((char**)&format);
		if (status == -1)
			return (-1);
		ret += status;
	}
	va_end(ap);
	return (ret);
}
