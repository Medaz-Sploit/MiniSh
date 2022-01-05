# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:14:28 by mazoukni          #+#    #+#              #
#    Updated: 2019/10/25 04:48:56 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC = 		ft_isalnum.c ft_memmove.c ft_split.c \
			ft_strlen.c ft_substr.c ft_isalpha.c \
			ft_memset.c ft_strchr.c ft_strmapi.c \
			ft_tolower.c ft_isascii.c ft_memccpy.c \
			ft_putchar_fd.c ft_strdup.c ft_strncmp.c    \
			ft_toupper.c ft_atoi.c ft_isdigit.c ft_memchr.c      \
			ft_putendl_fd.c ft_strjoin.c ft_strnstr.c ft_bzero.c       \
			ft_isprint.c ft_memcmp.c ft_putnbr_fd.c ft_strlcat.c     \
			ft_strrchr.c ft_calloc.c ft_itoa.c ft_memcpy.c \
			ft_putstr_fd.c ft_strlcpy.c ft_strtrim.c \
			ft_insert_element.c	

OBJ =		ft_isalnum.o ft_memmove.o ft_split.o \
			ft_strlen.o ft_substr.o ft_isalpha.o \
			ft_memset.o ft_strchr.o ft_strmapi.o \
			ft_tolower.o ft_isascii.o ft_memccpy.o \
			ft_putchar_fd.o ft_strdup.o ft_strncmp.o \
			ft_toupper.o ft_atoi.o ft_isdigit.o ft_memchr.o \
			ft_putendl_fd.o ft_strjoin.o ft_strnstr.o ft_bzero.o \
			ft_isprint.o ft_memcmp.o ft_putnbr_fd.o ft_strlcat.o \
			ft_strrchr.o ft_calloc.o ft_itoa.o ft_memcpy.o \
			ft_putstr_fd.o ft_strlcpy.o ft_strtrim.o \
			ft_insert_element.o

all : $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)
	ranlib	$(NAME)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f *.o

re: fclean all
