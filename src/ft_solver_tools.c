/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:43:51 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:58:15 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_size_lst(t_room *lst)
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

void			ft_sort_tab_ij(t_room **tab, int i, int j)
{
	int			k;
	t_room		*tmp;

	k = i + 1;
	while (k < j - 1)
	{
		if (tab[k]->cost > tab[k + 1]->cost)
		{
			tmp = tab[k];
			tab[k] = tab[k + 1];
			tab[k + 1] = tmp;
			k = i + 1;
		}
		else
			k++;
	}
}

int				file_is_ended(t_room **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		if (tab[i]->end == 1)
			return (1);
		i++;
	}
	return (0);
}

void			ft_print_tab(t_room **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		i++;
}

int				no_way(t_room **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		if (tab[i]->end == 1)
			return (1);
		i++;
	}
	return (0);
}
