/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:38:18 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:58:22 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_path_len_bis(t_sol2 *sol)
{
	int		i;

	i = 0;
	while (sol->path[i])
		i++;
	return (i);
}

int			**fill_tab_one_path_bis(int **tab, t_sol2 *sol, int ant)
{
	int		len;

	len = ft_path_len_bis(sol);
	tab[0][0] = len;
	tab[1][0] = len;
	tab[1][0] = ant;
	return (tab);
}

int			ft_count_paths_bis(t_sol2 *sol)
{
	int		i;

	i = 0;
	while (sol)
	{
		i++;
		sol = sol->next;
	}
	return (i);
}

int			*ft_fill_tab_bis(int *tab, t_sol2 *sol, int len)
{
	int		i;
	int		tmp;

	tmp = len;
	i = 0;
	while (tmp)
	{
		tab[i] = ft_path_len_bis(sol);
		sol = sol->next;
		i++;
		tmp--;
	}
	tab = ft_sort_tab(tab, len);
	return (tab);
}

int			ft_count_lines_bis(int ant, t_sol2 *sol)
{
	int		lines;
	int		path;
	int		**tab;

	path = ft_count_paths_bis(sol);
	if (path == 0)
		return (-1);
	tab = ft_memalloc(sizeof(int *) * 2);
	tab[0] = malloc(sizeof(int) * path);
	tab[1] = malloc(sizeof(int) * path);
	if (path == 1)
	{
		tab = fill_tab_one_path_bis(tab, sol, ant);
		sol->tab = ft_dup_int_tab(1, tab);
		ft_free_tab(tab);
		return (ft_path_len_bis(sol) + ant - 1);
	}
	else
	{
		tab[0] = ft_fill_tab_bis(tab[0], sol, path);
		lines = ft_spread_ants(tab, path, ant);
	}
	sol->tab = ft_dup_int_tab(path, tab);
	ft_free_tab(tab);
	return (lines);
}
