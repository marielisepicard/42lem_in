/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 09:51:02 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:58:49 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_solve_with_sup_room(t_room **tab, int i, t_room *room, int j)
{
	tab[i]->superposition = 1;
	if (!(old_prev_in_file(room, tab)))
	{
		ft_add_old_prev_in_file(room, tab, i, j);
		j++;
		ft_sort_tab_ij(tab, i, j);
	}
	return (j);
}

int				ft_find_j(t_room **tab)
{
	int			j;

	j = 0;
	while (tab[j])
		j++;
	return (j);
}

int				ft_solve_without_sup_room(t_room **tab, int i,
		t_room *room, t_room *lst)
{
	t_list		*voisin;
	int			j;

	j = ft_find_j(tab);
	voisin = tab[i]->neighbors;
	while (voisin)
	{
		if (!(voisin_in_file(voisin, tab)) &&
				((t_room*)(voisin->content))->prev != room &&
				!(((t_room*)(voisin->content))->superposition == 1))
		{
			ft_add_voisin_in_file(voisin, tab, lst, room);
			if (room->superposition == 2
					&& ((t_room*)(voisin->content))->forward
				&& room->path != ((t_room*)(voisin->content))->path)
				((t_room*)(voisin->content))->superposition = 1;
			else if (room->superposition == 2 &&
					((t_room*)(voisin->content))->forward)
				((t_room*)(voisin->content))->superposition = 2;
			j++;
			ft_sort_tab_ij(tab, i, j);
		}
		voisin = voisin->next;
	}
	return (j);
}
