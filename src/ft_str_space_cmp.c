/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_space_cmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:43:52 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:59:31 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_i(char **line)
{
	int		i;

	i = 1;
	while (line[i])
	{
		if (ft_strchr(line[i], '-'))
			break ;
		i++;
	}
	return (i);
}

int			ft_str_space_cmp(char const *s1, char const *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i] && s1[i] != ' ')
		i++;
	j = 0;
	while (s2[j] && s2[j] != ' ')
		j++;
	if (i != j)
		return (1);
	i = 0;
	while (i < j)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
