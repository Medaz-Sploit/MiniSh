# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 21:17:27 by mazoukni          #+#    #+#              #
#    Updated: 2022/02/08 15:06:17 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
LIBFT = libft/libft.a
FLAGS =  -lreadline -Wall -Werror -Wextra
SRC = srcs/Execution/*.c srcs/Parser/*.c srcs/minishell.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(SRC) $(LIBFT) $(FLAGS) -o $(NAME) 
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all