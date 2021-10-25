/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:41:40 by tlamart           #+#    #+#             */
/*   Updated: 2019/05/30 13:51:48 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s2)
		return (ft_strdup(s1));
	else if (!s1)
		return (ft_strdup(s2));
	else
	{
		if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		str = ft_strcpy(str, s1);
		str = ft_strcat(str, s2);
		return (str);
	}
}
