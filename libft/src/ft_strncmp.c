/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:57:04 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/21 16:12:12 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	while (*s1 && *s2 && n && *s1 == *s2)
	{
		++s1;
		++s2;
		--n;
	}
	if (!n)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
