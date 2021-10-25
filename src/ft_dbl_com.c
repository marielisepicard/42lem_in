/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:57:00 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 12:07:51 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_dbl_com_bis(char **line, int *i)
{
	if (ft_strncmp((line)[*i], "end", 3) != 0 ||
			ft_strncmp((line)[*i], "start", 5) != 0)
		return (0);
	return (1);
}

int			ft_dbl_com(char **line, int max)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	while (i < max - 1)
	{
		if (line[i][0] == '#' && line[i][1] == '#')
		{
			if (ft_strncmp(line[i], "##end", 6) == 0)
				end++;
			else if (ft_strncmp(line[i], "##start", 8) == 0)
				start++;
		}
		i++;
	}
	if (start == 1 && end == 1)
		return (0);
	return (1);
}
