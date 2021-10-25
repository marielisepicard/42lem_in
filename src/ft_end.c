/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:22:13 by tlamart           #+#    #+#             */
/*   Updated: 2019/09/04 12:15:54 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_null_sol(t_sol2 *sol)
{
	int		start;

	start = 0;
	while (sol)
	{
		sol->ant = NULL;
		if (!start)
			start++;
		else
			sol->tab = NULL;
		sol = sol->next;
	}
}

int		ft_init_ant(t_sol2 *sol)
{
	int		size;

	while (sol)
	{
		size = ft_pathlen(sol->path) + 1;
		if (!(sol->ant = (int*)ft_memalloc(sizeof(int) * size)))
			return (0);
		while (size - 1 >= 0)
		{
			sol->ant[size - 1] = 0;
			size--;
		}
		sol = sol->next;
	}
	return (1);
}

int		ft_file_ending_with_n(char *file)
{
	int		i;

	i = 0;
	while (file[i])
		i++;
	return (file[i - 1] == '\n' ? 1 : 0);
}

void	ft_dis(char **file, t_sol2 *sol, int ant, int i)
{
	int			res;

	res = 0;
	ft_putstr(*file);
	if (!i)
		ft_putstr("\n");
	ft_putstr("\n");
	res = ft_display_sol(sol, ant, 1, 0);
}

int		ft_lemend(char **file, t_sol2 *sol, int ant)
{
	int			i;

	if (sol && sol->path[0]->start && sol->path[1]->end)
		sol->special = 1;
	i = ft_file_ending_with_n(*file);
	if (!sol)
		ft_putstr_fd("ERROR\n", 2);
	else if (sol->special)
		ft_special_disp(*file, ant, i);
	else
	{
		ft_sort_sol(sol);
		ft_null_sol(sol);
		if (!(ft_init_ant(sol)))
			ft_putstr_fd("ERROR\n", 2);
		else
			ft_dis(file, sol, ant, i);
	}
	ft_strdel(file);
	if (sol)
		ft_free_sol2(sol);
	return (0);
}
