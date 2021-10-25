/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:56:01 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/12 10:14:03 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_advance_i(int i, char *str)
{
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-')))
		i++;
	return (i);
}

void	ft_pass_comments_and_commands(char **line, int *index)
{
	while (line[*index] && ((line[*index][0] == '#' && line[*index][1] != '#')
				|| (line[*index][0] == '#' && line[*index][1] == '#')))
		(*index)++;
}

int		find_line_len(char **line, int i)
{
	int		len;

	len = 0;
	while (line[i][len] && !ft_isspace(line[i][len]))
	{
		len++;
	}
	return (len);
}

int		find_dbl_room(char **line, int i, int max)
{
	int		j;
	int		len;

	j = i + 1;
	if (!line[i])
		return (0);
	len = find_line_len(line, i);
	while (j < max)
	{
		ft_pass_comments_and_commands(line, &j);
		if (!line[j])
			return (0);
		if (ft_strncmp(line[i], line[j], len + 1) == 0)
			return (1);
		j++;
	}
	return (0);
}

int		ft_dbl_room(char **line, int max)
{
	int		i;

	i = 0;
	ft_pass_comments(line, &i);
	i++;
	while (i < max)
	{
		ft_pass_comments_and_commands(line, &i);
		if (find_dbl_room(line, i, max))
		{
			return (1);
		}
		i++;
	}
	return (0);
}
