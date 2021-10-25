/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:02:57 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/21 16:05:54 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*cast_dst;
	const char		*cast_src;

	cast_dst = dst;
	cast_src = src;
	if (src < dst)
	{
		while (len)
		{
			cast_dst[len - 1] = cast_src[len - 1];
			len--;
		}
		return (dst);
	}
	while (len)
	{
		*cast_dst = *cast_src;
		cast_src++;
		cast_dst++;
		len--;
	}
	return (dst);
}
