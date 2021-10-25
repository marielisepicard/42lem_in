/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_sup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:36:40 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:57:38 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_clear_sup(t_room *lst)
{
	while (lst)
	{
		lst->superposition = 0;
		lst = lst->next;
	}
}

void			ft_add_sup_2(t_room **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		i++;
	i--;
	tab[i]->superposition = 2;
}

int				superpos(t_room **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		if (tab[i]->superposition != 0)
			return (1);
		i++;
	}
	return (0);
}

void			ft_null_prev_forw(t_room *tab)
{
	tab->prev = NULL;
	tab->forward = NULL;
}

void			ft_manage_sup(t_room **tab)
{
	t_room		*prev;
	t_room		*forw;
	int			i;

	i = 0;
	while (tab[i])
	{
		if (tab[i]->superposition != 0)
		{
			if (tab[i]->prev == tab[i]->old_forward
					&& tab[i]->forward == tab[i]->old_prev)
				ft_null_prev_forw(tab[i]);
			else
			{
				prev = tab[i]->prev;
				forw = tab[i]->forward;
				if (prev == tab[i]->old_forward)
					tab[i]->prev = tab[i]->old_prev;
				if (forw == tab[i]->old_prev)
					tab[i]->forward = tab[i]->old_forward;
			}
		}
		i++;
	}
}
