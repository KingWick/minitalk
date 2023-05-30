# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akram <akram@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 00:35:09 by akram             #+#    #+#              #
#    Updated: 2023/05/31 00:45:45 by akram            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	srcs/server.c \
				srcs/client.c \


OBJS 		= ${SRCS:.c=.o}
INCLUDES	= includes/
NAME		= minitalk
CC 			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all: 		${NAME}

%.o: %.c ./includes/minitalk.h
			${CC} ${CFLAGS} -I$(INCLUDES) -Imlx -Ibass -c $< -o ${<:.c=.o}
			@printf "\e[?25l\e[JCreated \e[92m$(notdir $@)\e[0m\r"

$(NAME): $(OBJS) 
	${CC} -o $(NAME) $(OBJS)
			@printf "\n\e[36msuccessfully\e[0m_\e[33m compiled \e[92mis ready !\e[0m\e[?25h\n"

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all
