# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 13:37:59 by arurangi          #+#    #+#              #
#    Updated: 2022/12/13 20:24:41 by Arsene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM
NAME		= 	so_long
LEVEL		=	001.ber
LIBFT		=	./src/libft/libft.a

# DIRECTORIES
SRC_DIR		=	./src/
UTILS_DIR	=	./src/utils/
LIBFT_DIR	=	./src/libft/
MAPS_DIR	=	./assets/maps/

# SOURCE FILES
SRCS		= 	$(SRC_DIR)main.c \
				$(SRC_DIR)map_checker.c \
				$(SRC_DIR)path_finder.c \
				$(SRC_DIR)render.c \
				$(SRC_DIR)input.c \
				$(SRC_DIR)initializer.c \
				$(SRC_DIR)load_assets.c \
				$(SRC_DIR)game_over.c \
				$(SRC_DIR)animate.c \
				$(UTILS_DIR)map_checker_utils.c \
				$(UTILS_DIR)path_finder_utils.c \
				$(UTILS_DIR)error_handling.c \
				$(UTILS_DIR)render_utils.c \
				$(UTILS_DIR)input_utils.c \
				$(UTILS_DIR)memory_management.c \
				$(UTILS_DIR)identify_walls.c \

# VARIABLES
COMPILER	= 	gcc
C_FLAGS		=	-Wall -Wextra -Werror
LIB_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
OBJ			=	${SRCS:.c=.o}
rm			=	rm -f

# RULES
%.o: 		%.c
				@$(COMPILER) $(C_FLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJ) $(LIBFT)
				@$(COMPILER) $(OBJ) $(LIBFT_DIR)libft.a  $(LIB_FLAGS) -o $(NAME)

$(LIBFT):
				@make -C $(LIBFT_DIR)

all:		$(NAME) 
			@./$(NAME) $(MAPS_DIR)$(LEVEL)

clean:
				@make -C ./src/libft fclean
				@rm -f $(OBJ) core

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

local:			$(LIBFT)
				@gcc  ./src/*.c ./src/utils/*.c -lX11 -lXext -lmlx -o so_long $(LIBFT)
				@./$(NAME)  $(MAPS_DIR)$(LEVEL)
