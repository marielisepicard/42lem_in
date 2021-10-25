/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:56:52 by tlamart           #+#    #+#             */
/*   Updated: 2019/02/08 13:37:02 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct	s_printf
{
	char	conv;
	int		(*printfct)(va_list ap, char*);
}				t_printf;

int				ft_printf(const char *restrict format, ...);
int				ft_printd(va_list ap, char *opt);
int				ft_prints(va_list ap, char *opt);
char			*itoprint(int n, int precision, char *opt);
char			*ltoprint(long n, int precision, char *opt);
char			*lltoprint(long long n, int precision, char *opt);
void			pf_findwidth_n_precision(char *str, int *width, int *precis);
void			pf_findwidth_n_precision_fl(char *str, int *width, int *precis);
int				pf_print(char *str, int strlen, int width, char *opt);
int				ft_printo(va_list ap, char *opt);
int				ft_printu(va_list ap, char *opt);
int				ft_printx(va_list ap, char *opt);
int				ft_printxm(va_list ap, char *opt);
int				ft_printfl(va_list ap, char *opt);
int				ft_printp(va_list ap, char *opt);
int				ft_printc(va_list ap, char *opt);

#endif
