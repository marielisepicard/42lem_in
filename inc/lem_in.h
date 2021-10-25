/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <mpicard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:48:09 by mpicard           #+#    #+#             */
/*   Updated: 2019/09/12 10:15:21 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct				s_room
{
	char					*name;
	t_list					*neighbors;
	int						visited;
	int						superposition;
	int						x;
	int						y;
	int						start;
	int						end;
	int						cost;
	int						path;
	struct s_room			*forward;
	struct s_room			*prev;
	struct s_room			*old_forward;
	struct s_room			*old_prev;
	struct s_room			*next;
	struct s_room			**adjacent;
}							t_room;

typedef struct				s_sol2
{
	t_room					**path;
	int						**tab;
	struct s_sol2			*next;
	int						*ant;
	char					special;
}							t_sol2;

void						ft_pass_commands_and_comments(char **line,
		int *index);
void						ft_pass_commands(char **line, int *index);
int							ft_bad_command(char **line, int *index);
void						ft_print_solution(t_sol2 *sol);
void						ft_print_lstt(t_room *lst);
int							ft_dbl_com(char **line, int max);
int							ft_dbl_com_bis(char **line, int *i);
int							ft_dbl_room(char **line, int max);
int							ft_advance_i(int i, char *str);
int							ft_ctablen(char **tab);
int							ft_pathlen(t_room **path);
void						ft_sort_sol(t_sol2 *sol);
void						ft_move_forward(int *ant, t_room **path);
int							ft_display_ant_room(t_room **path, int *ant);
void						ft_add_ant_or_not(int *ant_num, int nb_ant,
		t_sol2 *sol, int fill);
int							launch_parsing(t_room **lst, int *ant, char **line,
		char *file);
int							ft_ret_pars(char **line, int link, int status);
int							ft_return_with_link(char ***line);
int							ft_calc_status(char ***line, int *i, int *ant,
		t_room **lst);
int							check_solution2(t_sol2 *sol);
void						ft_actualize_rooms(t_room *lst, t_sol2 *sol);
t_sol2						*ft_create_final_sol_bis(t_room *lst);
void						repare_lst(t_room *lst);
int							ft_str_space_cmp(char const *s1, char const *s2);
int							ft_i(char **line);
t_sol2						*ft_special(t_list *lst);
void						ft_special_disp(char *file, int ant, int j);
int							ft_dup_room(t_room *lst);
int							unvalid_link(char *str, t_room *lst);
int							empty_line(char *str);
int							valid_lst(t_room *lst);
int							int_coord(char *str, int i);
int							ft_valid_coord(char **line);
int							ft_doublon(char **line);
void						ft_free_lst(t_room *lst);
void						ft_free_tab(int **tab);
void						ft_create_tab_for_one_ant2(t_sol2 *sol);
t_room						*ft_back_to_old_sol(t_room *lst);
void						ft_free_sol2(t_sol2 *sol);
int							ft_display_sol(t_sol2 *sol, int nb_ant, int ant,
		int lines);
int							ft_lemend(char **file, t_sol2 *sol, int ant);
int							ft_spread_ants(int **tab, int len, int ant);
int							**ft_dup_int_tab(int len, int **tab);
int							ft_count_lines_bis(int ant, t_sol2 *sol);
void						ft_add_voisin_in_file(t_list *voisin, t_room **tab,
		t_room *lst, t_room *room);
int							voisin_in_file(t_list *voisin, t_room **tab);
int							ft_tablen2(t_room *tab);
int							ft_size_lst(t_room *lst);
void						ft_sort_tab_ij(t_room **tab, int i, int j);
int							file_is_ended(t_room **tab);
int							no_way(t_room **tab);
void						ft_add_forward(t_room **tab, t_room *lst);
void						ft_delete_prev_without_forward(t_room *lst);
void						ft_add_old_prev_for(t_room *lst);
void						ft_add_old_prev_in_file(t_room *room, t_room **tab,
		int i, int j);
int							old_prev_in_file(t_room *room, t_room **tab);
void						ft_add_sup_2(t_room **tab);
int							superpos(t_room **tab);
void						ft_manage_sup(t_room **tab);
void						ft_clear_sup(t_room *lst);
t_sol2						*ft_solver(t_room *lst, int ant, int status,
		int lines_tmp);
void						print_new_sol(t_sol2 *sol);
int							ft_solve_with_sup_room(t_room **tab, int i,
		t_room *room, int j);
int							ft_solve_without_sup_room(t_room **tab, int i,
		t_room *room, t_room *lst);
void						ft_validate_sol(t_room *lst);
void						ft_clean_lst(t_room *lst);
int							*ft_sort_tab(int *tab, int len);
int							ft_new_tunnel(char *line, t_room *lst, int *index,
		char *sep);
int							ft_options(char **line, t_room **lst, int *i,
		int link);
int							ft_parsing_file(t_room **lst, int *ant,
		char ***line, int link);
t_room						*ft_init_lst(void);
void						ft_pass_comments(char **line, int *index);
int							ft_get_ant_num(char ***line, int *i, int *ant,
		t_room **init);
int							main(void);
void						ft_print_parsing(t_room *lst);

#endif
