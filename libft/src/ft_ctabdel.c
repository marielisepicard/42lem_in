/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctabdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:25:47 by tlamart           #+#    #+#             */
/*   Updated: 2019/08/21 14:55:10 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_ctabdel(char **tab)
{
	int		i;

	i = 0;
	while ((tab[i]))
	{
		free((tab[i]));
		(tab[i]) = NULL;
		i++;
	}
	free(tab);
}
