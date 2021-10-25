/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_sol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:16:22 by tlamart           #+#    #+#             */
/*   Updated: 2019/09/05 12:27:25 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_if_status(int status, int *lines)
{
	if (status)
	{
		ft_putchar('\n');
		(*lines)++;
	}
}

int		ft_display_sol(t_sol2 *sol, int nb_ant, int ant, int lines)
{
	t_sol2	*lst;
	int		status;
	int		sol_num;
	int		**tab;

	status = 1;
	tab = sol->tab;
	while (status)
	{
		status = 0;
		lst = sol;
		sol_num = 0;
		while (lst)
		{
			ft_add_ant_or_not(&ant, nb_ant, lst, tab[1][sol_num]);
			tab[1][sol_num] -= 1;
			status += ft_display_ant_room(lst->path, lst->ant);
			ft_move_forward(lst->ant, lst->path);
			lst = lst->next;
			sol_num++;
		}
		ft_if_status(status, &lines);
	}
	return (lines);
}
