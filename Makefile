# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 01:56:03 by fcatina           #+#    #+#              #
#    Updated: 2020/03/12 05:30:25 by fcatina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=\
	src/main.c \
	src/draw.c \
	src/do_key.c \
	src/change_param.c \
	src/get_num_matrix.c \
	src/get_struct_matrix.c \
	src/free_m_num_and_struct.c \
	src/print_background_and_menu.c \

OBJS=\
	src/main.o \
	src/draw.o \
	src/do_key.o \
	src/change_param.o \
	src/get_num_matrix.o \
	src/get_struct_matrix.o \
	src/free_m_num_and_str.ot.o \
	src/print_background_and_menu.o \

all:
	gcc -I libft/includes -L libft/ -lft -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror $(SRC) -o fdf
