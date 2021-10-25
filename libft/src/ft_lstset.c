/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:44:22 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/26 18:54:34 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstset(void *content, size_t content_size, size_t len)
{
	t_list	*begin;
	t_list	*lst;

	if (!len)
		return (NULL);
	if (!(begin = ft_lstnew(content, content_size)))
		return (NULL);
	len--;
	while (len > 0)
	{
		if (!(lst = ft_lstnew(content, content_size)))
		{
			ft_lstdel(&begin, &ft_lstdel_cnt);
			return (NULL);
		}
		ft_lstappend(&begin, lst);
		len--;
	}
	return (begin);
}
