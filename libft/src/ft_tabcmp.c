/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:15:04 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/02 12:41:32 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_tabcmp(char **s1, char **s2)
{
	int		len1;
	int		len2;
	int		i;

	len1 = 0;
	while (s1[len1] != NULL)
		len1++;
	i = 0;
	len2 = 0;
	while (s2[len2] != NULL)
		len2++;
	if (len1 != len2)
		return (1);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (ft_strcmp(s1[i], s2[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
