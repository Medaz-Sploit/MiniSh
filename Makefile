# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 21:17:27 by mazoukni          #+#    #+#              #
#    Updated: 2022/01/05 10:12:07 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
LDFLAG = -L 
CDFLAG = -I
FLAGS = -Wall -Wextra -Wall -lreadline
CDFLAG = -I /usr/local/opt/readline/include
LDFLAG = -L /usr/local/opt/readline/lib
SRC = srcs/*
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(CDFLAG) $(LDFLAG) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all