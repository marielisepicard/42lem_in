/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:34:21 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/02 12:38:33 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabdup(char **s1)
{
	char	**str;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	if (!(str = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[len] = NULL;
		i++;
	}
	str[len] = NULL;
	i = 0;
	while (i < len)
	{
		str[i] = ft_strdup(s1[i]);
		i++;
	}
	return (str);
}
