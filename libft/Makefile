# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 09:50:07 by tlamart           #+#    #+#              #
#    Updated: 2019/09/04 12:22:17 by mpicard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

SRCNAME = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c		\
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strlen.c ft_strmapi.c		\
	  ft_strequ.c ft_strcmp.c ft_strncmp.c ft_strnequ.c ft_strcpy.c			\
	  ft_strncpy.c ft_strsub.c ft_strcat.c ft_strncat.c ft_strjoin.c		\
	  ft_strtrim.c ft_strsplit.c ft_putchar.c ft_putstr.c ft_putendl.c		\
	  ft_itoa.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c	\
	  ft_putnbr_fd.c ft_strdup.c ft_memset.c ft_bzero.c ft_isalpha.c		\
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcpy.c		\
	  ft_memccpy.c ft_memmove.c ft_memcmp.c ft_memchr.c ft_strchr.c			\
	  ft_strrchr.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strstr.c			\
	  ft_strnstr.c ft_strlcat.c ft_lstnew.c ft_lstadd.c ft_lstdelone.c		\
	  ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_lstappend.c ft_lstdel_cnt.c	\
	  ft_isspace.c ft_lstcut_next.c ft_lstset.c get_next_line.c ft_lstlen.c	\
	  ft_swap.c ft_printc.c ft_printd.c ft_printf.c ft_printfl.c ft_printo.c\
	  ft_printp.c ft_prints.c ft_printu.c ft_printx.c itoprint.c lltoprint.c\
	  ltoprint.c tools.c ft_putnbrnl.c ft_lstnl.c ft_lstcreate.c ft_tabdel.c\
	  ft_tabclr.c ft_tabdup.c ft_tabcmp.c ft_tabtrim.c ft_ctabdel.c
SRCDIR = src/
SRC = $(addprefix $(SRCDIR), $(SRCNAME))


OBJNAME = $(SRCNAME:.c=.o)
OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(OBJNAME))

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h
INCDIR = inc/
INC = $(addprefix $(INCDIR), $(HEADER))

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	@ar rc $(NAME) $(OBJ) 
	@ranlib $(NAME)
	@echo "\nlibft done"

$(OBJDIR)%.o : $(SRCDIR)%.c $(INC)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I $(INCDIR) -c -o $@ $<
	@printf "%-42s\r" "compiling $@"

clean :
	@rm -rf $(OBJDIR)
	@echo 'libft clean'

fclean :
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)
	@echo 'libft fclean'

re : fclean all
