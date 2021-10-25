/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:12:04 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/12 10:11:09 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_pass_comments(char **line, int *index)
{
	while (line[*index] && line[*index + 1] && line[*index][0] == '#'
			&& line[*index][1] != '#')
		(*index)++;
}

int		ft_get_ant_num(char ***line, int *i, int *ant, t_room **init)
{
	int		idx;

	ft_pass_commands_and_comments(*line, i);
	*init = NULL;
	idx = 0;
	while (ft_isspace((*line)[*i][idx]))
		idx++;
	if ((*line)[*i][idx] == '-')
		return (0);
	else if ((*line)[*i][idx] == '+')
		idx++;
	else if ((ft_strlen((*line)[*i] + idx) == 10
	&& ft_strcmp((*line)[*i], "2147483647") > 0))
		return (0);
	else if (ft_strlen(((*line)[*i]) + idx) > 10)
		return (0);
	while (ft_isdigit((*line)[*i][idx]))
		idx++;
	while (ft_isspace((*line)[*i][idx]))
		idx++;
	if (((*line)[*i][idx]) || ((*ant = ft_atoi((*line)[*i])) <= 0))
		return (0);
	(*i)++;
	return (1);
}

t_room	*ft_init_lst(void)
{
	t_room		*new;

	if (!(new = (t_room*)(malloc(sizeof(t_room)))))
		return (NULL);
	new->name = NULL;
	new->superposition = 0;
	new->end = 0;
	new->cost = 0;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	new->neighbors = NULL;
	new->start = 0;
	new->prev = NULL;
	new->forward = NULL;
	new->old_forward = NULL;
	new->old_prev = NULL;
	new->path = 0;
	new->next = NULL;
	return (new);
}

int		ft_new_room(char **line, t_room *lst, int *index, int link)
{
	t_room		*room;
	int			i;

	if (line[*index][0] == 'L' || link || ft_isspace(line[*index][0]))
	{
		if (!link)
			return (-1);
		return (7);
	}
	if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (-1);
	i = 0;
	while (line[*index][i] && line[*index][i] != ' ')
		i++;
	if (!(room->name = ft_strsub(line[*index], 0, i)))
		return (-1);
	room->neighbors = NULL;
	room->next = lst->next;
	lst->next = room;
	(*index)++;
	return (0);
}

int		ft_parsing_file(t_room **lst, int *ant, char ***line, int link)
{
	int			i;
	int			status;
	char		*sep;

	i = 0;
	status = ft_calc_status(line, &i, ant, lst);
	while ((*line)[i] && !status)
	{
		ft_pass_commands_and_comments(*line, &i);
		if ((*line)[i] && (*line)[i][0] == '#')
		{
			if (link)
				return (ft_return_with_link(line));
			status = ft_options((*line), lst, &i, link);
		}
		else if ((*line)[i] && ((sep = ft_strchr((*line)[i], '-'))
					&& (*sep != (*line)[i][0] && *(sep - 1) != ' ')))
		{
			link = 1;
			status = ft_new_tunnel((*line)[i], *lst, &i, sep);
		}
		else if ((*line)[i])
			status = ft_new_room((*line), *lst, &i, link);
	}
	return (ft_ret_pars(*line, link, status));
}
