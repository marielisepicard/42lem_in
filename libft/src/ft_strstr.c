/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:44:15 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/21 16:08:19 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		if (!(haystack = ft_strchr(haystack, *needle)))
			return (NULL);
		i = 0;
		while (needle[i] && needle[i] == haystack[i])
			i++;
		if (!needle[i])
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
