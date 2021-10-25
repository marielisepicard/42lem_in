/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:13:40 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/21 15:38:42 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || !*s)
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_strncpy(str, s + start, len);
	return (str);
}
