/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:53:26 by tlamart           #+#    #+#             */
/*   Updated: 2019/08/20 16:36:08 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if (!(mem = malloc(size)))
		return (NULL);
	while (i < size)
	{
		*(char*)(mem + i) = 0x00;
		i++;
	}
	return (mem);
}
