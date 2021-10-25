/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sol2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:27:39 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 12:00:22 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			repare_lst(t_room *lst)
{
	t_room			*start;

	start = lst;
	while (lst)
	{
		if (lst->old_prev == start)
			lst->prev = start;
		lst = lst->next;
	}
}

t_sol2			*add_new_sol2(t_sol2 *sol, t_room *lst, int len, t_room *start)
{
	t_sol2		*new;
	t_room		**path;
	int			i;

	new = ft_memalloc(sizeof(t_sol2));
	new->path = NULL;
	new->tab = NULL;
	path = ft_memalloc(sizeof(t_room) * (len * 2));
	path[0] = start;
	i = 1;
	path[i] = lst;
	while (path[i] && path[i]->end == 0)
	{
		i++;
		path[i] = path[i - 1]->forward;
	}
	new->path = path;
	new->next = sol;
	return (new);
}

int				ft_tablen5(t_room *lst)
{
	int			i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_sol2			*ft_create_final_sol_bis(t_room *lst)
{
	t_sol2		*sol;
	t_room		*start;
	int			len;

	sol = NULL;
	start = lst;
	repare_lst(start);
	lst = lst->next;
	len = ft_tablen5(start);
	while (lst)
	{
		if (lst->prev == start)
			sol = add_new_sol2(sol, lst, len, start);
		lst = lst->next;
	}
	return (sol);
}
