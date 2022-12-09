# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 15:45:01 by afonso            #+#    #+#              #
#    Updated: 2022/12/09 11:38:45 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell
HEADER := -I./ -I./built-ins/
OBJDIR:= ./Objects
BIOBJ:= ./built-ins/built-in_objs
OBJS:= 
OBJS_built-in:=
#OBJS_T :=
CC := gcc
CFLAGS := -g -Wall -Wextra -Werror #-fsanitize=address
RM := rm -f

all:minishell

OBJS_built-in:
	${MAKE} -C ./built-ins all

minishell: OBJS_built-in $(OBJS)
	${CC} ${CFLAGS} ${NAME}.c ${OBJS} ${HEADER} -o ${NAME}
	mv *.o ./Objects

test:${OBJS}
	${CC} -g -Wextra -Wall teste.c ${OBJS} ${HEADER} -o tester
	
clean:
	${RM} *.o
	${RM} tester
	${MAKE} -C ./built-ins/ clean

fclean: clean
	${RM} minishell

re: fclean all

 .PHONY:linux test