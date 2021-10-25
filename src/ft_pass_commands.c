/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:43:50 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/12 12:11:43 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_bad_command(char **line, int *index)
{
	if (line[*index] && ft_strcmp(line[*index], "##start") != 0
			&& ft_strcmp(line[*index], "##end") != 0)
		return (1);
	return (0);
}

void		ft_pass_commands(char **line, int *index)
{
	while (line[*index] && line[*index + 1] && line[*index][0] == '#'
			&& line[*index][1] == '#'
			&& ft_strcmp(line[*index], "##start") != 0
			&& ft_strcmp(line[*index], "##end") != 0)
		(*index)++;
}

void		ft_pass_commands_and_comments(char **line, int *index)
{
	if (line[*index] && (line[*index][0] != '#'
		|| ft_strcmp(line[*index], "##start") == 0
		|| ft_strcmp(line[*index], "##end") == 0))
		return ;
	ft_pass_commands(line, index);
	ft_pass_comments(line, index);
	if (!line[*index] || !line[*index + 1])
		return ;
	ft_pass_commands_and_comments(line, index);
}
