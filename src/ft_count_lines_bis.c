/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:32:36 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/04 11:59:03 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_find_sum(int len, int **tab)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (i < len)
	{
		sum = sum + tab[1][i];
		i++;
	}
	return (sum);
}

int			ft_return_the_ant(int **tab, int ant)
{
	if (ant < 0)
		return (-1);
	else
		return (tab[0][0] + tab[1][0] - 1);
}

int			**ft_spread_the_left(int **tab, int i, int left)
{
	while (left > 0 && i > 0)
	{
		tab[1][i] = tab[1][i] + 1;
		left--;
		i--;
	}
	return (tab);
}

int			ft_spread_ants(int **tab, int len, int ant)
{
	int		i;
	int		left;
	int		divid;

	i = 1;
	tab[1][0] = 1;
	while (i < len)
	{
		tab[1][i] = tab[1][i - 1] + (tab[0][i - 1] - tab[0][i]);
		i++;
	}
	ant = ant - ft_find_sum(len, tab);
	if (ant <= 0)
		return (ft_return_the_ant(tab, ant));
	divid = ant / len;
	left = ant % len;
	i = 0;
	while (i < len)
	{
		tab[1][i] = tab[1][i] + divid;
		i++;
	}
	if (left)
		tab = ft_spread_the_left(tab, len - 1, left);
	return (tab[1][len - 1] + tab[0][len - 1] - 1);
}
