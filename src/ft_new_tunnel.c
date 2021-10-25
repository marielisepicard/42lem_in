/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tunnel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:44:37 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/05 11:06:41 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_find_first_room(t_room **lst, char **line, char **sep, t_room **lst1)
{
	while (*lst && *line && *sep)
	{
		if (ft_strequ(*line, (*lst)->name))
		{
			*lst1 = *lst;
			*line = NULL;
		}
		else if (ft_strequ(*sep, (*lst)->name))
		{
			*lst1 = *lst;
			*sep = NULL;
		}
		(*lst) = (*lst)->next;
	}
}

void	ft_find_second_room(t_room **lst, char **line,
		char **sep, t_room **lst2)
{
	while (*lst && *line)
	{
		if (ft_strequ(*line, (*lst)->name))
		{
			*lst2 = *lst;
			*line = NULL;
		}
		(*lst) = (*lst)->next;
	}
	while (*lst && *sep)
	{
		if (ft_strequ(*sep, (*lst)->name))
		{
			*lst2 = *lst;
			*sep = NULL;
		}
		(*lst) = (*lst)->next;
	}
}

int		existing_link(t_list *add1, t_list *list)
{
	while (list)
	{
		if (ft_strcmp(((t_room*)(add1->content))->name,
					((t_room*)(list->content))->name) == 0)
			return (1);
		list = list->next;
	}
	return (0);
}

int		ft_add_tunnel(t_room *lst1, t_room *lst2, int *index)
{
	t_list	*add1;
	t_list	*add2;

	if (!(add1 = (t_list*)(ft_memalloc(sizeof(t_list)))))
		return (-1);
	add1->content = (void*)lst2;
	if (existing_link(add1, lst1->neighbors) && lst1->name != NULL)
	{
		free(add1);
		return (42);
	}
	ft_lstadd(&(lst1->neighbors), add1);
	if (!(add2 = (t_list*)(ft_memalloc(sizeof(t_list)))))
		return (-1);
	add2->content = (void*)lst1;
	ft_lstadd(&(lst2->neighbors), add2);
	(*index)++;
	return (0);
}

int		ft_new_tunnel(char *line, t_room *lst, int *index, char *sep)
{
	t_room		*lst1;
	t_room		*lst2;
	t_room		*head;

	head = lst;
	*sep = '\0';
	sep++;
	if (ft_strequ(line, sep))
	{
		(*index)++;
		return (42);
	}
	lst1 = NULL;
	lst2 = NULL;
	ft_find_first_room(&lst, &line, &sep, &lst1);
	ft_find_second_room(&lst, &line, &sep, &lst2);
	lst = head;
	if (!lst1 || !lst2)
		return (42);
	return (ft_add_tunnel(lst1, lst2, index));
}
