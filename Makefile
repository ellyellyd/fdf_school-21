# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 01:56:03 by fcatina           #+#    #+#              #
#    Updated: 2020/03/04 21:41:58 by fcatina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=*.c

all:
	gcc -I libft/includes -L libft/ -lft -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror $(SRC) -o fdf
