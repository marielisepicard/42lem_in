/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:15:27 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/26 16:58:47 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	begin = (*f)(lst);
	lst = lst->next;
	while (lst)
	{
		if (!(new = (*f)(lst)))
		{
			ft_lstdel(&begin, &ft_lstdel_cnt);
			return (NULL);
		}
		ft_lstappend(&begin, new);
		lst = lst->next;
	}
	return (begin);
}
