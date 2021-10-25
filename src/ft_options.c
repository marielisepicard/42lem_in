/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:31:18 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/12 12:11:57 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_start2(t_room **lst)
{
	(*lst)->start = 1;
	(*lst)->cost = 0;
	(*lst)->superposition = 0;
	(*lst)->path = 0;
	(*lst)->old_prev = NULL;
	(*lst)->old_forward = NULL;
	(*lst)->end = 0;
	(*lst)->prev = NULL;
	(*lst)->forward = NULL;
}

int		ft_start(char **line, t_room **lst, int *index, int i)
{
	int			j;
	static int	count = 0;

	if (!line[*index])
		return (42);
	if (count > 0)
		return (-42);
	while (line[*index][i] && ft_isspace(line[*index][i]))
		i++;
	j = i;
	while (line[*index][j] && !ft_isspace(line[*index][j]))
		j++;
	if (!((*lst)->name = ft_strsub(line[*index], i, j)))
		return (-1);
	ft_start2(lst);
	(*index)++;
	count++;
	return (0);
}

void	ft_end2(t_room *end)
{
	end->end = 1;
	end->start = 0;
	end->prev = NULL;
	end->cost = 0;
	end->forward = NULL;
	end->superposition = 0;
}

int		ft_end(char **line, t_room **lst, int *index)
{
	int			i;
	t_room		*end;
	static int	count = 0;

	if (count > 0)
		return (-42);
	i = 0;
	if (!(end = ft_init_lst()))
		return (-1);
	while (line[*index][i] && line[*index][i] != ' ')
		i++;
	if (!(end->name = ft_strsub(line[*index], 0, i)))
		return (-1);
	ft_end2(end);
	end->path = 0;
	end->old_prev = NULL;
	end->old_forward = NULL;
	end->next = (*lst)->next;
	(*lst)->next = end;
	(*index)++;
	count++;
	return (0);
}

int		ft_options(char **line, t_room **lst, int *i, int link)
{
	if (ft_strequ("##start", line[*i]))
	{
		*i = *i + 1;
		ft_pass_commands_and_comments(line, i);
		if (!line[*i])
			return (42);
		if (line[*i] && (line[*i][0] == 'L' || line[*i][0] == '#'
					|| ft_isspace(line[*i][0])))
			return (-1);
		return (ft_start(line, lst, i, 0));
	}
	else if (ft_strequ("##end", line[*i]))
	{
		*i = *i + 1;
		ft_pass_commands_and_comments(line, i);
		if (!line[*i])
			return (42);
		return ((line[*i][0] == 'L' || line[*i][0] == '#'
					|| ft_isspace(line[*i][0])) ? -1
				: ft_end(line, lst, i));
	}
	(*i)++;
	(void)link;
	return (0);
}
