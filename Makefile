# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 04:08:24 by abucia            #+#    #+#              #
#    Updated: 2022/08/19 04:08:24 by abucia           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC		=	src/check.c \
src/exec.c \
src/main.c \
src/parsing.c \
src/utils.c \

HEADER = includes/header.h

NAME	=	philo

CC		=	gcc
FLAGS	= 	-Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS)

%.o : %.c $(HEADER)
	$(CC) $(FLAG) -c $< -o $@

$(NAME) : all

re : fclean $(NAME)

clean :
	@rm -rf $(OBJ) $(OBJ_B)
	@echo "$(GREEN)************ $@ clean !$(RST)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(GREEN)************ $@ fclean !$(RST)"

.PHONY: NAME all clean fclean re
