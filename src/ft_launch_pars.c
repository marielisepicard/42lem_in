/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:14:00 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/12 12:03:13 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_ret_pars(char **line, int link, int status)
{
	(void)line;
	if (status == -1)
		return (0);
	if (!link)
		return (0);
	if (status == 2)
		return (0);
	if (status == 42)
		return (1);
	return (status < 0 ? 0 : 1);
}

int		ft_return_with_link(char ***line)
{
	(void)line;
	return (-1);
}

int		ft_calc_status(char ***line, int *i, int *ant, t_room **lst)
{
	int	status;

	status = !(ft_get_ant_num(line, i, ant, lst)) ? -7 : 0;
	if (status == -7)
		return (-1);
	if (!(*lst = ft_init_lst()))
		status = -7;
	else
		status = 0;
	return (status);
}

int		launch_parsing(t_room **lst, int *ant, char **line, char *file)
{
	if (!(ft_parsing_file(lst, ant, &line, 0)))
	{
		ft_putstr_fd("ERROR\n", 2);
		if (line)
			ft_ctabdel(line);
		ft_free_lst(*lst);
		if (file)
			ft_strdel(&file);
		return (0);
	}
	if (line)
		ft_ctabdel(line);
	return (1);
}
