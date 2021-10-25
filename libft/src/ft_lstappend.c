/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:18:47 by tlamart           #+#    #+#             */
/*   Updated: 2019/04/22 12:58:27 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	list = *lst;
	while (list->next)
		list = list->next;
	list->next = new;
	new->next = NULL;
}
