/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:24:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 12:00:28 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_ctablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_pathlen(t_room **path)
{
	int		i;

	i = 0;
	while (path[i])
		i++;
	return (i);
}

void	ft_sort_sol(t_sol2 *sol)
{
	t_room	**tmp;
	t_sol2	*ptr;

	ptr = sol;
	while (ptr->next)
	{
		if (ft_pathlen(ptr->path) < ft_pathlen(ptr->next->path))
		{
			tmp = ptr->path;
			ptr->path = ptr->next->path;
			ptr->next->path = tmp;
			ptr = sol;
		}
		else
			ptr = ptr->next;
	}
}
