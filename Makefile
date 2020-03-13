# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 01:56:03 by fcatina           #+#    #+#              #
#    Updated: 2020/03/14 00:33:20 by fcatina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean norm libft memcheck

NAME = fdf

SRC_DIR = src
OBJ_DIR = obj

MAIN_RAW = main.c
MAIN = $(addprefix $(SRC_DIR)/,$(MAIN_RAW))

CC = gcc
LFLAGS = 
CFLAGS = -Wall -Wextra -Werror

SRC_RAW = \
	draw.c \
	do_key.c \
	change_param.c \
	get_num_matrix.c \
	get_struct_matrix.c \
	free_m_num_and_struct.c \
	print_background_and_menu.c \

SRC = $(addprefix $(SRC_DIR)/,$(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_RAW:.c=.o))

all: $(NAME)

$(NAME): libft $(OBJ_DIR) $(OBJ) 
	$(CC) $(LFLAGS) -I libft/includes -L libft/ -lft -lmlx -framework OpenGL -framework AppKit $(OBJ) $(MAIN) -o $(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I libft/includes -c $< -o $@
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
libft:
	make -C libft/

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft/
fclean: clean
	rm -f $(NAME)
	make fclean -C libft/ 
re: fclean all

norm:
	norminette $(SRC_DIR)/ libft/src/ libft/includes/

memcheck:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) test_maps/42.fdf
