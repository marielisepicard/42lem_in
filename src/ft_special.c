/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:43:21 by tlamart           #+#    #+#             */
/*   Updated: 2019/09/09 17:40:19 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_endname(char *file)
{
	char	*end;
	int		i;

	end = ft_strstr(file, "\n##end\n") + 7;
	while (end && *end == '#')
		end = ft_strchr(end, '\n') + 1;
	if (!end)
		return (NULL);
	i = 0;
	while (end[i] && end[i] != ' ')
		i++;
	end[i] = '\0';
	return (end);
}

void	ft_special_disp(char *file, int ant, int j)
{
	char	*end;

	ft_putstr(file);
	ft_putstr("\n");
	if (!j)
		ft_putstr("\n");
	end = ft_endname(file);
	while (ant > 0)
	{
		ft_printf("L%d-%s ", ant, end);
		ant--;
	}
	ft_putchar('\n');
}

t_sol2	*ft_special_sol(void)
{
	t_sol2	*sol;

	if (!(sol = (t_sol2*)ft_memalloc(sizeof(t_sol2))))
		return (NULL);
	sol->special = 1;
	return (sol);
}

t_sol2	*ft_special(t_list *lst)
{
	t_room	*room;
	t_sol2	*sol;

	while (lst)
	{
		room = (t_room*)lst->content;
		if (room->end)
			return ((sol = ft_special_sol()));
		lst = lst->next;
	}
	return (NULL);
}
