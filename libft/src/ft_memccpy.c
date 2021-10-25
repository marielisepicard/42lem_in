/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:32:50 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/21 16:05:42 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*cast_dst;
	unsigned const char	*cast_src;
	char				*null;
	size_t				i;

	cast_dst = dst;
	cast_src = src;
	i = 0;
	while (i < n && cast_src[i] != (unsigned char)c)
	{
		cast_dst[i] = cast_src[i];
		i++;
	}
	if (i == n)
	{
		null = NULL;
		return (null);
	}
	else
	{
		cast_dst[i] = (unsigned char)c;
		return (dst + i + 1);
	}
}
