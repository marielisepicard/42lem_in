/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_neighbors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:48:04 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 12:00:04 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_tablen2(t_room *tab)
{
	int			i;

	i = 0;
	while (tab)
	{
		tab = tab->forward;
		i++;
	}
	return (i);
}

int				voisin_in_file(t_list *voisin, t_room **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(((t_room*)(voisin->content))->name, tab[i]->name) == 0)
			return (1);
		i++;
	}
	return (0);
}

void			ft_add_voisin_in_file(t_list *voisin, t_room **tab,
		t_room *lst, t_room *room)
{
	int			i;
	t_room		*new;

	i = 0;
	while (tab[i])
		i++;
	tab[i] = ((t_room*)(voisin->content));
	new = tab[i];
	new->prev = room;
	if (new->cost == 0)
		new->cost = room->cost + 1;
	(void)lst;
}
