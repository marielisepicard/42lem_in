/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:56:39 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/12 12:12:04 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_norm_get_file(char **file, char *buf, int res)
{
	char	*tmp;
	char	*new;
	int		i;

	if (!file)
		return (-1);
	i = 0;
	if (!*file && buf[0] == '\n')
		return (1);
	while (buf[i + 1])
	{
		if (buf[i + 1] && buf[i] == '\n' && buf[i + 1] == '\n')
		{
			new = ft_strsub(buf, 0, i);
			res = 1;
			break ;
		}
		i++;
	}
	tmp = *file;
	*file = (res ? (ft_strjoin(*file, new)) : ft_strjoin(*file, buf));
	if (res)
		ft_strdel(&new);
	ft_strdel(&tmp);
	return (res);
}

static char	*ft_get_file(void)
{
	char	*file;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		status;

	file = NULL;
	while ((ret = read(0, buf, BUFF_SIZE)) && ret != -1)
	{
		buf[ret] = '\0';
		if ((status = ft_norm_get_file(&file, buf, 0)))
		{
			if (status == -1)
				return (NULL);
			if (status == 1)
				break ;
		}
	}
	if (ret == -1)
	{
		ft_strdel(&file);
		perror("ft_get_file");
	}
	return (file);
}

int			error_case(char *file, char **line)
{
	int		max;

	max = ft_i(line);
	if (!(ft_valid_coord(line))
			|| ft_dbl_room(line, max))
	{
		ft_putstr("ERROR \n");
		if (file)
			ft_strdel(&file);
		if (line)
			ft_ctabdel(line);
		return (1);
	}
	return (0);
}

int			error_case_after_parsing(t_room *lst, char *file)
{
	if (!(valid_lst(lst)))
	{
		ft_putstr("ERROR\n");
		ft_free_lst(lst);
		ft_strdel(&file);
		return (1);
	}
	return (0);
}

int			main(void)
{
	char		*file;
	char		**line;
	int			ant;
	t_room		*lst;
	t_sol2		*sol2;

	if (!(file = ft_get_file())
			|| !(line = ft_strsplit(file, '\n')))
	{
		ft_strdel(&file);
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	if (error_case(file, line))
		return (0);
	if (!(launch_parsing(&lst, &ant, line, file)))
		return (0);
	if (error_case_after_parsing(lst, file))
		return (0);
	sol2 = ft_solver(lst, ant, 1, 0);
	ft_lemend(&file, sol2, ant);
	ft_free_lst(lst);
	return (0);
}
