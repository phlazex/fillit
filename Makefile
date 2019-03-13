# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 12:44:55 by mfahey            #+#    #+#              #
#    Updated: 2019/03/07 15:44:10 by kreilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit_main.c\
	  fillit_buff.c\
	  fillit_first_valid.c\
	  fillit_second_valid.c\
	  fillit_structure.c\
	  fillit_algorithm.c\
	  fillit_move.c

OBJ = fillit_main.o\
	  fillit_buff.o\
	  fillit_first_valid.o\
	  fillit_second_valid.o\
	  fillit_structure.o\
	  fillit_algorithm.o\
	  fillit_move.o

HDR = /

HDRLFT = libft

MKCMD = make -C

RMCMD = rm -rf

GCC = gcc -g -Wall -Wextra -Werror

all: $(NAME) Makefile

$(NAME): $(OBJ)
	$(MKCMD) $(HDRLFT)
	$(GCC) $(OBJ) -L$(HDRLFT) -lft -o $(NAME)

$(OBJ): %.o: %.c
	$(GCC) -c $< -o $@ -I $(HDR) -I $(HDRLFT)

clean:
	$(RMCMD) $(OBJ)
	$(MKCMD) $(HDRLFT) clean

fclean: clean
	$(RMCMD) $(NAME)
	$(MKCMD) $(HDRLFT) fclean

re: fclean all
	$(MKCMD) $(HDRLFT) re
