# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/07 15:21:24 by akdjebal          #+#    #+#              #
#    Updated: 2022/05/27 17:51:19 by akdjebal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_toolbox.c \
		ft_toolbox1.c \

OBJS = ${SRCS:.c=.o}

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}
		
.c.o:
		${CC} ${CC_FLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re 