# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 00:35:09 by akram             #+#    #+#              #
#    Updated: 2023/07/27 17:58:05 by akdjebal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CLIENT	= srcs/client.c ft_printf/ft_toolbox.c ft_printf/ft_toolbox1.c ft_printf/ft_printf.c
SRCS_SERVER	= srcs/server.c srcs/tools.c ft_printf/ft_toolbox.c ft_printf/ft_toolbox1.c ft_printf/ft_printf.c

OBJS_CLIENT	= ${SRCS_CLIENT:.c=.o}
OBJS_SERVER	= ${SRCS_SERVER:.c=.o}

INCLUDES	= includes/
NAME_CLIENT	= client
NAME_SERVER	= server
NAME  		= minitalk
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3 
RM			= rm -f

GREY=\033[0;37m
RED=\033[0;31m
GREEN= \033[92m
YELLOW=\033[1;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
ORANGE = \033[0;33m
CYAN=\033[0;36m
WHITE=\033[1;37m
BIRed=\033[1;91m
END=\033[0m

all: $(NAME_CLIENT) $(NAME_SERVER)

%.o: %.c ./includes/minitalk.h
	${CC} ${CFLAGS} -I$(INCLUDES) -c $< -o ${<:.c=.o}

$(NAME_SERVER): $(OBJS_SERVER)
	${CC} -o $(NAME_SERVER) $(OBJS_SERVER)
	@echo "${BLUE}successfully${YELLOW} compiled $(NAME_SERVER) ${GREEN}is ready !${END}"
	
$(NAME_CLIENT): $(OBJS_CLIENT)
	${CC} -o $(NAME_CLIENT) $(OBJS_CLIENT)
	@echo "${BLUE}successfully${YELLOW} compiled $(NAME_CLIENT) ${GREEN}is ready !${END}"

clean:
	${RM} ${OBJS_CLIENT} ${OBJS_SERVER}
	@echo "${WHITE}.o files ${BIRed}were successfully ${RED}deleted !${END}"
	
fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all
