/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_sol2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:07:17 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:58:40 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_free_sol2(t_sol2 *sol)
{
	t_sol2		*temp;

	free(sol->tab[0]);
	free(sol->tab[1]);
	free(sol->tab);
	while (sol)
	{
		temp = sol->next;
		free(sol->path);
		free(sol->ant);
		free(sol);
		sol = temp;
	}
}
