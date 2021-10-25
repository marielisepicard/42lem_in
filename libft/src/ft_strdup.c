/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:38:36 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/05 11:35:12 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(s1))))
		return (NULL);
	str = ft_strcpy(str, s1);
	return (str);
}
