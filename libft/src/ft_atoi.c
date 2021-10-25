/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:23:01 by tlamart           #+#    #+#             */
/*   Updated: 2019/08/30 11:02:31 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		res;
	int		s;

	res = 0;
	s = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * s);
}
