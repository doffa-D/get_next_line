# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 15:39:11 by hdagdagu          #+#    #+#              #
#    Updated: 2022/10/24 12:35:18 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= get_next_line.c \
	get_next_line_utils.c \

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
AR = ar rcs

all:$(NAME)
	
$(NAME): $(OBJ)
	$(AR) $@ $^

%.o%.c:
	$(CC) $(CFLAGS) -c $^ -o $@ 

fclean:
	rm -rf $(NAME) $(OBJ)
clean: 
	rm -rf $(OBJ)
re:fclean $(NAME)
