/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actualize_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:30:55 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:56:44 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_null_prev_for_lst(t_room *lst)
{
	while (lst)
	{
		lst->prev = NULL;
		lst->forward = NULL;
		lst->old_prev = NULL;
		lst->old_forward = NULL;
		lst = lst->next;
	}
}

void		ft_actualize_rooms_by_sol(t_sol2 *sol, t_room *lst, t_room *start)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	sol->path[i]->prev = start;
	sol->path[0]->forward = sol->path[i];
	while (sol->path[i + 1])
	{
		sol->path[i]->prev = sol->path[j];
		sol->path[i]->old_prev = sol->path[i]->prev;
		sol->path[i]->forward = sol->path[i + 1];
		sol->path[i]->old_forward = sol->path[i]->forward;
		i++;
		j++;
	}
	sol->path[i]->prev = sol->path[i - 1];
	(void)lst;
}

void		ft_actualize_rooms(t_room *lst, t_sol2 *sol)
{
	t_room	*start;
	int		i;
	int		j;

	start = lst;
	i = 1;
	j = 0;
	ft_null_prev_for_lst(lst);
	while (sol)
	{
		ft_actualize_rooms_by_sol(sol, lst, start);
		sol = sol->next;
	}
}
