/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:35:09 by tlamart           #+#    #+#             */
/*   Updated: 2019/09/01 15:19:40 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# define BUFF_SIZE 4096

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strdup(const char *s1);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_atoi(const char *str);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t len);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstappend(t_list **lst, t_list *new);
void			ft_lstdel_cnt(void *content, size_t content_size);
int				ft_isspace(int c);
void			ft_lstcut_next(t_list **lst);
t_list			*ft_lstset(void *content, size_t content_size, size_t len);
int				get_next_line(const int fd, char **line);
int				ft_lstlen(t_list *list);
void			ft_swap(char *a, char *b);
int				ft_printf(const char *format, ...);
void			ft_putnbrnl(int nb);
int				ft_lstnl(t_list **list, const void *content,
				size_t content_size);
t_list			*ft_lstcreate(void *content, size_t content_size);
void			ft_tabdel(char ***tab);
char			**ft_tabdup(char **s1);
int				ft_tabcmp(char **s1, char **s2);
int				ft_tabisprint(char *str);
char			**ft_tabtrim(char **str, int len);
void			ft_ctabdel(char **tab);

#endif
