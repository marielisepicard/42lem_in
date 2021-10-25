/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_former_sol.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:56:11 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:59:39 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*ft_back_to_old_sol(t_room *lst)
{
	t_room		*head;

	head = lst;
	while (lst)
	{
		lst->prev = lst->old_prev;
		lst->forward = lst->old_forward;
		lst = lst->next;
	}
	return (head);
}
