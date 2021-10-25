/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:45:50 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/05 11:51:57 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_number_sol(t_sol2 *sol)
{
	int			i;
	int			nb;

	i = 0;
	nb = 1;
	while (sol)
	{
		i = 0;
		while (sol->path[i])
		{
			sol->path[i]->path = nb;
			i++;
		}
		nb++;
		sol = sol->next;
	}
}

t_sol2			*ft_make_sol_and_return_sol2(t_room **tab, t_room *lst)
{
	t_sol2		*sol;

	sol = NULL;
	if (!(no_way(tab)))
	{
		lst = ft_back_to_old_sol(lst);
		if (!(no_way(tab)))
		{
			free(tab);
			return (NULL);
		}
	}
	ft_add_forward(tab, lst);
	ft_delete_prev_without_forward(lst);
	if (superpos(tab))
		ft_manage_sup(tab);
	sol = ft_create_final_sol_bis(lst);
	ft_number_sol(sol);
	free(tab);
	return (sol);
}

t_sol2			*ft_solver_bis_2(t_room *lst)
{
	t_room		**tab;
	t_room		*room;
	t_list		*voisin;
	int			i;
	int			j;

	i = 0;
	j = 1;
	tab = ft_memalloc(sizeof(t_room) * (ft_size_lst(lst) * 9));
	tab[0] = lst;
	voisin = NULL;
	while (!file_is_ended(tab))
	{
		room = tab[i];
		if (tab[i]->forward != NULL && !tab[i]->start &&
				tab[i]->superposition != 2)
			j = ft_solve_with_sup_room(tab, i, room, j);
		else
			j = ft_solve_without_sup_room(tab, i, room, lst);
		i++;
		if (i == j)
			break ;
	}
	return (ft_make_sol_and_return_sol2(tab, lst));
}

t_sol2			*ft_return_soltmp(t_sol2 *sol, t_sol2 *sol_tmp)
{
	if (sol != sol_tmp)
		ft_free_sol2(sol);
	return (sol_tmp);
}

t_sol2			*ft_solver(t_room *lst, int ant, int status, int lines_tmp)
{
	t_sol2		*sol;
	t_sol2		*sol_tmp;
	int			lines;

	sol_tmp = NULL;
	sol = NULL;
	while (status)
	{
		sol = ft_solver_bis_2(lst);
		if (!sol)
			break ;
		ft_clear_sup(lst);
		lines = ft_count_lines_bis(ant, sol);
		if ((lines_tmp != 0 && lines_tmp < lines) || (lines == -1))
			return (ft_return_soltmp(sol, sol_tmp));
		else
			ft_actualize_rooms(lst, sol);
		if (ant == 1)
			ft_create_tab_for_one_ant2(sol);
		lines_tmp = lines;
		if (sol_tmp)
			ft_free_sol2(sol_tmp);
		sol_tmp = sol;
	}
	return ((!sol) ? sol_tmp : sol);
}
