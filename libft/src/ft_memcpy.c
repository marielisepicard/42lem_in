/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:02:48 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/21 16:05:35 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*cast_dst;
	const char	*cast_src;

	i = 0;
	cast_dst = dst;
	cast_src = src;
	while (i < n)
	{
		cast_dst[i] = cast_src[i];
		i++;
	}
	return (dst);
}
