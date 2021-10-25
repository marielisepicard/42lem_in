/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:54:49 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:58:03 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_free_nei(t_list *lst)
{
	t_list		*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

void			ft_free_lst(t_room *lst)
{
	t_room		*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst->name);
		ft_free_nei(lst->neighbors);
		free(lst);
		lst = temp;
	}
}

void			ft_free_tab(int **tab)
{
	free(tab[0]);
	free(tab[1]);
	free(tab);
}
