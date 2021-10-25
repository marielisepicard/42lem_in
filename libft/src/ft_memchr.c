/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:46:44 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/21 16:06:02 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*cast_s;
	unsigned char			cast_c;

	cast_s = (const unsigned char*)s;
	cast_c = (unsigned char)c;
	while (n)
	{
		if (*cast_s == cast_c)
			return (((void*)cast_s));
		++cast_s;
		--n;
	}
	return (NULL);
}
