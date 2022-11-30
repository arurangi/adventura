# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 13:37:59 by arurangi          #+#    #+#              #
#    Updated: 2022/11/30 16:20:26 by Arsene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
SRCS	= 	src/so_long.c \
			src/draw_map.c \
			src/map_checker.c \
			src/map_checker_utils.c \
			src/path_finder.c \
			src/path_finder_utils.c \
			src/error_handling.c \
			libft/ft_strlen.c \
			libft/ft_putchar.c \
			libft/ft_putstr.c \
			libft/ft_putnbr.c \
			libft/ft_putnbr_mod.c \
			libft/ft_putnbr_u.c \
			libft/ft_isalpha.c \
			libft/ft_puthex.c \
			libft/ft_putfs.c \
			libft/ft_printf.c \
			libft/get_next_line.c \
			libft/get_next_line_utils.c \
			libft/ft_split.c \
			libft/ft_strjoin.c \
			libft/ft_split_fd.c \
			

# VARIABLES
NAME	= 	so_long
CC		= 	gcc
FLAGS	=	-Wall -Wextra -Werror
OBJ		=	${SRCS:.c=.o}

# RULES
%.o: 		%.c
				@$(CC) ${FLAGS} -Imlx -c $< -o $@

$(NAME): 	$(OBJ)
				@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

all:		${NAME}

local:
			@gcc src/*.c libft/*.c -lX11 -lXext -lmlx -o so_long
			@./${NAME} assets/maps/000.ber

map:		${NAME}
				@./${NAME} assets/maps/000.ber

clean:		
			@rm ${OBJ}

fclean:		clean
				@rm ${NAME}

re:			fclean all

.PHONY:		all clean fclean re