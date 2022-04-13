# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 17:08:04 by ibaines           #+#    #+#              #
#    Updated: 2022/04/13 12:32:17 by ibaines          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c \
	  ft_split.c \
	  ft_splitraro.c \
	  ft_putstr.c \
	  ft_strjoin.c \
	  ft_utils.c

OBJS = pipex.o \
	   ft_split.o \
	   ft_splitraro.o \
	   ft_strjoin.o \
	   ft_putstr.o \
	   ft_utils.o

CC = gcc

HEADER = includes/pipex.h

FLAGS = -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $^ -o $@
#	@mkdir objs
#	@mv $(OBJS) ./objs

clean:
		@/bin/rm -f $(OBJS)
		@/bin/rm -Rf obj

fclean: clean
		@/bin/rm -rf $(NAME)
		@/bin/rm -rf objs
		@/bin/rm -rf *.dSYM

re: fclean all

.PHONY: all clean fclean re
