/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:05:30 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:57:49 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			*ft_sort_tab(int *tab, int len)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 1;
	while (j < len)
	{
		if (tab[i] < tab[j])
		{
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
			i = 0;
			j = 1;
		}
		else
		{
			i++;
			j++;
		}
	}
	return (tab);
}

int			**ft_dup_int_tab(int len, int **tab)
{
	int		**final;
	int		i;

	final = ft_memalloc(sizeof(int *) * 2);
	final[0] = ft_memalloc(sizeof(int) * len);
	final[1] = ft_memalloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		final[0][i] = tab[0][i];
		final[1][i] = tab[1][i];
		i++;
	}
	return (final);
}
