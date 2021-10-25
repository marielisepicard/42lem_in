# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpicard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 14:52:00 by mpicard           #+#    #+#              #
#    Updated: 2019/09/12 12:20:05 by tlamart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRCNAME =	main.c ft_parsing.c ft_options.c ft_new_tunnel.c ft_count_lines.c \
			 ft_solver.c \
		    ft_solver_sup.c \
	   		ft_solver_prev_forw.c ft_solver_tools.c ft_solver_neighbors.c \
		   ft_count_lines_bis.c  ft_create_former_sol.c \
		   ft_display_sol.c ft_end.c ft_one_ant.c ft_free_lst.c \
		   ft_special.c ft_str_space_cmp.c \
		   ft_errors.c ft_create_sol2.c ft_count_lines2.c \
		   ft_solver2.c ft_free_sol2.c actualize_rooms.c  \
		   ft_display_sol2.c ft_end2.c ft_dbl_room.c ft_launch_pars.c \
		   ft_dbl_com.c ft_pass_commands.c

SRCDIR = src/
SRC = $(addprefix $(SRCDIR), $(SRCNAME))
OBJNAME = $(SRCNAME:.c=.o)
OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(OBJNAME))
CC = clang
CFLAGS = -Wall -Wextra  -Werror
INCDIR = inc/
HEADER = libft.h	\
 		 lem_in.h
INC = $(addprefix $(INCDIR), $(HEADER))
LIB = libft/ -lft

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@echo "linking obj"
	@$(CC) -o $@ $^ -L $(LIB) 
	@echo "$@ successfully created"

$(OBJDIR)%.o : $(SRCDIR)%.c $(INC)
	@mkdir -p $(OBJDIR)
	@echo "compiling $@"
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

clean :
	make clean -C libft
	@echo "cleaning obj"
	@rm -rf $(OBJDIR)

fclean : clean
	make fclean -C libft
	@echo "cleaning exec"
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
