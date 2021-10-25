/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:59:17 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 12:00:34 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			find_len_of_sol2(t_sol2 *sol)
{
	int		i;

	i = 0;
	while (sol->path[i])
		i++;
	return (i);
}

void		ft_create_tab_for_one_ant2(t_sol2 *sol)
{
	int		len;
	int		**tab;

	len = find_len_of_sol2(sol);
	if (!(tab = ft_memalloc(sizeof(int *) * 2)))
		return ;
	if (!(tab[0] = ft_memalloc(sizeof(int))))
		return ;
	if (!(tab[1] = ft_memalloc(sizeof(int))))
		return ;
	tab[0][0] = len;
	tab[1][0] = 1;
	if (sol->tab)
	{
		free(sol->tab[0]);
		free(sol->tab[1]);
		free(sol->tab);
	}
	sol->tab = ft_dup_int_tab(1, tab);
	free(tab[0]);
	free(tab[1]);
	free(tab);
}
