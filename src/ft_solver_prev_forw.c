/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_prev_forw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:40:04 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 12:00:42 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_add_forward(t_room **tab, t_room *lst)
{
	t_room		*prev;
	t_room		*forward;
	t_room		*tmp;
	int			i;

	i = 0;
	while (tab[i] && tab[i]->end != 1)
		i++;
	tmp = tab[i];
	prev = NULL;
	forward = NULL;
	while (tab[i] && tab[i]->start != 1)
	{
		prev = tab[i]->prev;
		prev->forward = tab[i];
		tab[i] = prev;
	}
	tab[i] = tmp;
	(void)lst;
}

void			ft_delete_prev_without_forward(t_room *lst)
{
	while (lst)
	{
		if (lst->start == 0 && lst->end == 0)
		{
			if (lst->prev && !lst->forward)
				lst->prev = NULL;
		}
		lst = lst->next;
	}
}

void			ft_add_old_prev_for(t_room *lst)
{
	while (lst)
	{
		if (lst->start == 0 && lst->end == 0)
		{
			lst->old_forward = lst->forward;
			lst->old_prev = lst->prev;
		}
		lst = lst->next;
	}
}

void			ft_add_old_prev_in_file(t_room *room,
		t_room **tab, int i, int j)
{
	t_room		*old_prev;

	old_prev = room->old_prev;
	old_prev->superposition = 2;
	old_prev->prev = room;
	tab[j] = old_prev;
	(void)i;
}

int				old_prev_in_file(t_room *room, t_room **tab)
{
	t_room		*old_prev;
	int			i;

	old_prev = room->old_prev;
	i = 0;
	while (tab[i])
	{
		if (tab[i] == old_prev)
			return (1);
		i++;
	}
	return (0);
}
