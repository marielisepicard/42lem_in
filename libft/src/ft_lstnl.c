/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 08:36:25 by tlamart           #+#    #+#             */
/*   Updated: 2019/03/27 08:57:57 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstnl(t_list **list, void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = ft_lstnew(content, content_size)))
		return (0);
	ft_lstappend(list, new);
	return (1);
}
