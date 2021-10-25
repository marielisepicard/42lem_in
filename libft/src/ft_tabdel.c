/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:28:17 by tlamart           #+#    #+#             */
/*   Updated: 2019/06/22 13:56:51 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabdel(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		ft_strdel(&(*tab)[i]);
		i++;
	}
	ft_strdel(&(*tab)[i]);
	free(*tab);
	*tab = NULL;
}
