/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:45:04 by tlamart           #+#    #+#             */
/*   Updated: 2019/07/09 12:03:24 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_search_end_of_line(char **bol, char **line)
{
	char	*eol;
	char	*tmp;

	while ((eol = ft_strchr(*bol, '\n')))
	{
		*line = ft_strsub(*bol, 0, eol - *bol);
		tmp = *bol;
		*bol = ft_strdup(eol + 1);
		ft_strdel(&tmp);
		if (!(*line) || !*bol)
			return (-1);
		return (1);
	}
	return (0);
}

int		ft_read(const int fd, char **line, char **bol)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) && ret != -1)
	{
		buf[ret] = '\0';
		tmp = *bol;
		*bol = ft_strjoin(*bol, buf);
		ft_strdel(&tmp);
		if (!*bol)
			return (-1);
		if ((ret = ft_search_end_of_line(bol, line)))
			return (ret);
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char	*bol = NULL;
	int			status;

	if (!line || (!bol && !(bol = ft_strnew(0))))
		return (-1);
	if ((status = ft_read(fd, line, &bol)))
		return (status);
	if ((status = ft_search_end_of_line(&bol, line)))
		return (status);
	if (*bol)
	{
		*line = bol;
		bol = ft_strnew(0);
	}
	ft_strdel(&bol);
	return (0);
}
