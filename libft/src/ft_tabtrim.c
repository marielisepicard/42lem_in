/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:04:16 by mpicard           #+#    #+#             */
/*   Updated: 2019/07/09 12:15:27 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabtrim(char **str, int len)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (len + 1));
	res[len] = NULL;
	i = 0;
	while (i < len)
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	return (res);
}
