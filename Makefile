# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 13:37:59 by arurangi          #+#    #+#              #
#    Updated: 2022/11/19 15:18:33 by arurangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
SRCS	= 	src/so_long.c \
			src/my_mlx_pixel_put.c \
			libft/ft_strlen.c \
			libft/ft_putchar.c \
			libft/ft_putstr.c \
			libft/ft_putnbr.c \
			libft/ft_putnbr_u.c \
			libft/ft_isalpha.c \
			libft/ft_puthex.c \
			libft/ft_putfs.c \
			libft/ft_printf.c 

# VARIABLES
NAME	= 	runthis
CC		= 	gcc
OBJ		=	${SRCS:.c=.o}

# RULES
%.o: 		%.c
				@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): 	$(OBJ)
				@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

r:			${NAME}
				@./${NAME}

clean:		${NAME}
				@rm ${OBJ}
fclean:		${NAME}
				@rm ${OBJ} ${NAME}
re:
				fclean all

.PHONY:
				all clean fclean re