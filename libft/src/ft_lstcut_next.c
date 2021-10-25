/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:30:40 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/26 19:10:44 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcut_next(t_list **lst)
{
	t_list	*cut;
	t_list	*tmp;

	cut = (*lst)->next;
	tmp = cut->next;
	ft_lstdelone(&cut, &ft_lstdel_cnt);
	(*lst)->next = tmp;
}
