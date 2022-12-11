# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 13:37:59 by arurangi          #+#    #+#              #
#    Updated: 2022/12/11 20:54:59 by Arsene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM
NAME		= 	so_long
LEVEL		=	002.ber
LEVEL_B		=	002.ber
LIBFT		=	./src/libft/libft.a

# DIRECTORIES
MANDATORY	=	./src/mandatory/
BONUS		=	./src/bonus/
LIBFT_DIR	=	./src/libft/
MAPS_DIR	=	./assets/maps/
MAPS_DIR_B	=	./assets/maps/bonus/

# SOURCE FILES
SRCS		=	$(MANDATORY)main.c \
				$(MANDATORY)map_checker.c \
				$(MANDATORY)utils/map_checker_utils.c \
				$(MANDATORY)path_finder.c \
				$(MANDATORY)utils/path_finder_utils.c \
				$(MANDATORY)utils/error_handling.c \
				$(MANDATORY)render.c \
				$(MANDATORY)utils/render_utils.c \
				$(MANDATORY)input.c \
				$(MANDATORY)utils/input_utils.c \
				$(MANDATORY)initializer.c \
				$(MANDATORY)load_assets.c \
				$(MANDATORY)game_over.c \
				${MANDATORY}utils/memory_management.c \

SRCS_B		= 	$(BONUS)main_bonus.c \
				$(BONUS)map_checker_bonus.c \
				$(BONUS)utils/map_checker_utils_bonus.c \
				$(BONUS)path_finder_bonus.c \
				$(BONUS)utils/path_finder_utils_bonus.c \
				$(BONUS)utils/error_handling_bonus.c \
				$(BONUS)render_bonus.c \
				$(BONUS)utils/render_utils_bonus.c \
				$(BONUS)input_bonus.c \
				$(BONUS)utils/input_utils_bonus.c \
				$(BONUS)initializer_bonus.c \
				$(BONUS)load_assets_bonus.c \
				$(BONUS)game_over_bonus.c \
				${BONUS}utils/memory_management_bonus.c \
				${BONUS}animate_bonus.c \
				${BONUS}utils/identify_walls_bonus.c \

# VARIABLES
COMPILER	= 	gcc
C_FLAGS		=	-Wall -Wextra -Werror
LIB_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
OBJ			=	${SRCS:.c=.o}
OBJ_B		=	${SRCS_B:.c=.o}
rm			=	rm -f
#DEPS		=	./src/libft/libft.h

# RULES
%.o: 		%.c
				@$(COMPILER) $(C_FLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJ) $(LIBFT)
				@$(COMPILER) $(OBJ) $(LIBFT_DIR)libft.a  $(LIB_FLAGS) -o $(NAME)
$(LIBFT):
				@make -C $(LIBFT_DIR)

all:		$(NAME) 
			
play:		${NAME}
			@./$(NAME) $(MAPS_DIR)$(LEVEL)

clean:
				@make -C ./src/libft fclean
				@rm -f $(OBJ) $(OBJ_B) core

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

bonus:		$(OBJ_B) $(LIBFT)
				@$(COMPILER) $(OBJ_B) $(LIBFT_DIR)libft.a  $(LIB_FLAGS) -o $(NAME)
				@./$(NAME) $(MAPS_DIR_B)$(LEVEL_B)

local:			$(LIBFT)
				@gcc  $(MANDATORY)*.c $(MANDATORY)utils/*.c -lX11 -lXext -lmlx -o so_long $(LIBFT)
				@./$(NAME)  $(MAPS_DIR)$(LEVEL)

local_bonus:	$(LIBFT)
				@gcc $(BONUS)*.c $(BONUS)utils/*.c -lX11 -lXext -lmlx -o so_long $(LIBFT)
				@./$(NAME) $(MAPS_DIR_B)$(LEVEL_B)