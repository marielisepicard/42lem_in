/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:06:51 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/12 10:10:33 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			empty_line(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == '\n' && str[i + 1] && str[i + 1] == '\n')
		{
			i--;
			while (i > 0 && str[i] && str[i] != '\n')
				i--;
			i++;
			while (str[i] && str[i] != '\n')
			{
				if (str[i] == '-')
					return (0);
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int			valid_lst(t_room *lst)
{
	int		i;

	i = 0;
	if (lst->start != 1)
		return (0);
	return (1);
}

int			int_coord(char *str, int i)
{
	if (str[0] == '#')
		return (1);
	i = ft_advance_i(i, str);
	if (!str[i])
		return (0);
	while (str[i] && !ft_isspace(str[i]))
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (0);
	if (str[i] && ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-')))
		i++;
	while (str[i] && !ft_isspace(str[i]))
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (str[i] ? 0 : 1);
}

int			ft_valid_coord(char **line)
{
	int		i;
	int		x;

	i = 0;
	ft_pass_commands_and_comments(line, &i);
	i++;
	if (line[i])
		ft_pass_commands_and_comments(line, &i);
	x = i;
	while (line[i])
	{
		if (!(ft_strchr(line[i], '-')))
			i++;
		else
			break ;
	}
	while (x < i - 1)
	{
		if (line[x][0] == '#')
			x++;
		else if (!(int_coord(line[x], 0)))
			return (0);
		x++;
	}
	return (1);
}

int			ft_doublon(char **line)
{
	int		i;
	int		j;
	int		k;

	i = ft_i(line);
	if (!(line[i]))
		return (-1);
	j = 1;
	k = 2;
	while (j < i)
	{
		while (k < i)
		{
			if (line[j][0] == '#')
				j++;
			else if (ft_str_space_cmp(line[i], line[k]) == 0)
				return (1);
			k++;
		}
		j++;
		k = j + 1;
	}
	return (0);
}
