/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:52:25 by tlamart           #+#    #+#             */
/*   Updated: 2019/02/09 15:01:15 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		pf_findwidth_n_precision(char *str, int *width, int *precis)
{
	char	*dot;
	int		i;

	i = 0;
	if ((dot = ft_strchr(str, '.')))
		*precis = ft_atoi(dot + 1);
	else
		(*precis = 1);
	*width = 0;
	while (str[i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]))
		{
			if (i == 1 && str[i] == '0')
				i++;
			else
			{
				*width = ft_atoi(str + i);
				return ;
			}
		}
		else
			i++;
	}
}

void		pf_findwidth_n_precision_fl(char *str, int *width, int *precis)
{
	char	*dot;
	int		i;

	i = 0;
	if ((dot = ft_strchr(str, '.')))
		*precis = ft_atoi(dot + 1);
	else
		(*precis = 6);
	*width = 0;
	while (str[i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]))
		{
			if (i == 1 && str[i] == '0')
				i++;
			else
			{
				*width = ft_atoi(str + i);
				return ;
			}
		}
		else
			i++;
	}
}

static char	find_conv(char *str)
{
	while (*(str + 1))
		str++;
	return (*str);
}

int			pf_print(char *str, int strlen, int width, char *opt)
{
	char	fill;

	fill = ' ';
	if (((!ft_strchr(opt, '.') && !ft_strchr(opt, '-')) ||\
			find_conv(opt) == 'f') && *(opt + 1) == '0')
		fill = '0';
	if (!ft_strchr(opt, '-'))
	{
		while (strlen < width)
		{
			ft_putchar(fill);
			strlen++;
		}
	}
	ft_putstr(str);
	while (strlen < width)
	{
		ft_putchar(fill);
		strlen++;
	}
	return (strlen);
}
