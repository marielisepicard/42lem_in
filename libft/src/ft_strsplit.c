/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:16:32 by tlamart           #+#    #+#             */
/*   Updated: 2019/09/01 15:47:58 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *s, char c)
{
	if (!*s || *s == c)
		return (0);
	return (1 + ft_wordlen(++s, c));
}

static size_t	ft_wordcount(char const *s, char c)
{
	if (!*s)
		return (0);
	else if (ft_wordlen(s, c))
		return (1 + (ft_wordcount(s + ft_wordlen(s, c), c)));
	else
		return (ft_wordcount(++s, c));
}

static void		ft_deltab(char ***tab, size_t size)
{
	if (tab)
	{
		while (size)
		{
			if (tab[size - 1])
			{
				ft_strdel(tab[size - 1]);
				size--;
			}
			else
				return ;
		}
	}
}

static char		**ft_cpy(char const *s, char c, char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			if (!(tab[i] = ft_strnew(ft_wordlen(s, c))))
				return (NULL);
			while (*s && *s != c)
			{
				tab[i][j] = *s;
				s++;
				j++;
			}
			i++;
		}
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_wordcount(s, c);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
		return (NULL);
	if (!(tab = ft_cpy(s, c, tab)))
	{
		ft_deltab(&tab, len + 1);
		ft_strdel(tab);
		return (NULL);
	}
	tab[len] = 0;
	return (tab);
}
