/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:06:30 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/26 09:47:57 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	strt;
	size_t			end;

	if (!s)
		return (NULL);
	if (!ft_strlen(s))
		return (ft_strnew(0));
	strt = 0;
	while (s[strt] && (s[strt] == ' ' || s[strt] == '\n' || s[strt] == '\t'))
		strt++;
	end = ft_strlen(s) - 1;
	while (end > 0 && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	end++;
	if (end <= strt)
		return (ft_strnew(0));
	return (ft_strsub(s, strt, end - strt));
}
