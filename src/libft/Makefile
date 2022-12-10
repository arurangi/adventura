# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 07:27:54 by Arsene            #+#    #+#              #
#    Updated: 2022/12/10 16:25:06 by arurangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_strlen.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putnbr_mod.c \
			ft_putnbr_u.c \
			ft_isalpha.c \
			ft_puthex.c \
			ft_putfs.c \
			ft_printf.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_split.c \
			ft_strjoin.c \
			ft_split_fd.c \
			ft_itoa.c \

NAME =		libft.a

OBJS =		${SRCS:.c=.o}
OBJSB =		${SRCSB:.c=.o}

FLAGS =		-Wall -Wextra -Werror 
CC =		gcc $(FLAGS)
RM =		rm -f

all:		$(NAME)

%.o: 		%.c
				@$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME) :	$(OBJS)
				@ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(OBJSB)
				@ar rcs $(NAME) $(OBJS) $(OBJSB)

clean:
				@$(RM) $(OBJS) $(OBJSB)

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
