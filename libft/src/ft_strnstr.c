/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:10:22 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/26 15:58:19 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + 1] && haystack[i] != needle[j] && i < len)
			i++;
		if (haystack[i] == needle[j])
		{
			while (i + j < len && haystack[i + j] == needle[j] && needle[j])
				j++;
			if (!(needle[j]))
				return ((char*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
