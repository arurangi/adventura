# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 11:26:27 by arurangi          #+#    #+#              #
#    Updated: 2022/11/19 12:19:11 by arurangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		libft/ft_printf.c \
			libft/ft_strlen.c \
			libft/ft_putchar.c \
			libft/ft_putstr.c \
			libft/ft_putnbr.c \
			libft/ft_putnbr_u.c \
			libft/ft_isalpha.c \
			libft/ft_puthex.c \
			libft/ft_putfs.c

NLIB =		libft.a
NPROG =		runthis

OBJS =		${SRCS:.c=.o}

FLAGS =		-Wall -Wextra -Werror 
CC =		gcc ${FLAGS}
RM =		rm -f

${NLIB} :	${OBJS}
				@ar rcs ${NLIB} ${OBJS}

all:		${NLIB}

run:	${NLIB}
				@${CC} -o runthis src/main.c libft.a
				@./${NPROG}
clean:
				@${RM} ${OBJS}

fclean:		clean
				@${RM} ${NLIB} ${NPROG}

re:			fclean all

.PHONY:		all clean fclean re