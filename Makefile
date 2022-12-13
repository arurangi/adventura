# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 13:37:59 by arurangi          #+#    #+#              #
#    Updated: 2022/12/13 20:13:32 by Arsene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM
NAME		= 	so_long
LEVEL		=	001.ber
LIBFT		=	./src/libft/libft.a

# DIRECTORIES
LIBFT_DIR	=	./src/libft/
MAPS_DIR	=	./assets/maps/

# SOURCE FILES
SRCS		= 	./src/main_bonus.c \
				./src/map_checker_bonus.c \
				./src/utils/map_checker_utils_bonus.c \
				./src/path_finder_bonus.c \
				./src/utils/path_finder_utils_bonus.c \
				./src/utils/error_handling_bonus.c \
				./src/render_bonus.c \
				./src/utils/render_utils_bonus.c \
				./src/input_bonus.c \
				./src/utils/input_utils_bonus.c \
				./src/initializer_bonus.c \
				./src/load_assets_bonus.c \
				./src/game_over_bonus.c \
				./src/utils/memory_management_bonus.c \
				./src/animate_bonus.c \
				./src/utils/identify_walls_bonus.c \

# VARIABLES
COMPILER	= 	gcc
C_FLAGS		=	-Wall -Wextra -Werror
# LIB_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
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
