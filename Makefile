# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupin <lupin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 13:37:59 by arurangi          #+#    #+#              #
#    Updated: 2023/05/27 12:27:46 by lupin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM
NAME		= 	so_long
lvl			=	5
LEVEL		=	00$(lvl).ber
LIBFT		=	./src/libft/libft.a

# DIRECTORIES
SRC_DIR		=	./src/
UTILS_DIR	=	./src/utils/
LIBFT_DIR	=	./src/libft/
MAPS_DIR	=	./assets/maps/
#MLX_PATH	=	$(CURDIR)/mlx_mod/
MLX_PATH	=	/Users/lupin/Desktop/cursus/so_long/mlx/
X11_PATH	=	/usr/X11/lib/

# SOURCE FILES
SRCS		= 	$(SRC_DIR)main.c \
				$(SRC_DIR)map_checker.c \
				$(SRC_DIR)path_finder.c \
				$(SRC_DIR)render.c \
				$(SRC_DIR)input.c \
				$(SRC_DIR)initializer.c \
				$(SRC_DIR)load_assets.c \
				$(SRC_DIR)animate.c \
				$(SRC_DIR)display.c \
				$(UTILS_DIR)map_checker_utils.c \
				$(UTILS_DIR)path_finder_utils.c \
				$(UTILS_DIR)error_handling.c \
				$(UTILS_DIR)render_utils.c \
				$(UTILS_DIR)input_utils.c \
				$(UTILS_DIR)memory_management.c \
				$(UTILS_DIR)identify_walls.c \

# VARIABLES
COMPILER	= 	gcc
C_FLAGS		=	-Wall -Wextra -Werror $(SANITIZE)
SANITIZE	=	#-g -fsanitize=address
FRAMEWORK	=	-framework OpenGL -framework AppKit
LIB_FLAGS	=	-L$(X11_PATH) -lX11 -lXext -L$(MLX_PATH) -lmlx 
OBJ			=	${SRCS:.c=.o}
rm			=	rm -f
INC			=	-I./includes -I./src/libft -I./mlx

LIBX		=	/Users/lupin/Documents/education/coding/cursus/so_long/minilibx-linux

# RULES
# %.o: 		%.c
# 				@$(COMPILER) $(C_FLAGS) -Imlx -c $< -o $@

%.o: %.c
	$(COMPILER) $(C_FLAGS) $(INC) -Imlx -c $< -o $@

$(NAME): 	$(OBJ) $(LIBFT)
				@$(COMPILER) $(C_FLAGS) $(OBJ) $(LIBFT_DIR)libft.a $(LIB_FLAGS) $(FRAMEWORK) -o $(NAME)

$(LIBFT):
				@make -C $(LIBFT_DIR)

all:		$(NAME) 

sub-module:
			git submodule update --init --recursive

run:
			./$(NAME) $(MAPS_DIR)$(LEVEL)

clean:
				@make -C ./src/libft fclean
				@rm -f $(OBJ) core

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

local:			$(LIBFT)
				@gcc $(C_FLAGS) ./src/*.c ./src/utils/*.c $(LIB_FLAGS) -o so_long $(LIBFT)
				@./$(NAME)  $(MAPS_DIR)$(LEVEL)
