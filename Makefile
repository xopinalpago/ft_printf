# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 14:27:30 by jermarti          #+#    #+#              #
#    Updated: 2023/05/15 10:37:29 by rmeriau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRSRC		= ./srcs/

DIRINC		= ./includes/

DIRLIB		= ./libft/

SRC			= ft_printf ft_printf_utils

SRCS		= $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

HEAD		= ./includes/ 

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc
RM			= rm -f
AR			= ar rc

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
