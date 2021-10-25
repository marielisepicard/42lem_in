/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_sol2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:17:22 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:59:11 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_add_ant_or_not(int *ant_num, int nb_ant, t_sol2 *sol, int fill)
{
	if (*ant_num <= nb_ant && fill > 0)
	{
		sol->ant[1] = *ant_num;
		*ant_num += 1;
	}
}

int		ft_display_ant_room(t_room **path, int *ant)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (path[i])
	{
		if (ant[i])
		{
			ft_printf("L%d-%s ", ant[i], (path[i])->name);
			count++;
		}
		i++;
	}
	return (count);
}

void	ft_move_forward(int *ant, t_room **path)
{
	int		i;

	i = 1;
	while (path[i])
		i++;
	while (i > 0)
	{
		ant[i] = ant[i - 1];
		i--;
	}
}
