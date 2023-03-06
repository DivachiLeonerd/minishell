# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 15:45:01 by afonso            #+#    #+#              #
#    Updated: 2023/03/06 15:15:45 by afonso           ###   ########.fr        #
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

libbuilt-in.a:
	${MAKE} -C ./built-ins all && cd ./built-ins && mv libbuilt-in.a ../

libtree.a:
	${MAKE} -C ./tree all && cd ./tree && mv libtree.a ../
	
minishell: built-in tree
	${CC} ${CFLAGS} ${NAME}.c ${OBJS} ${HEADER} -o ${NAME}
	mv *.o ./Objects

test: libbuilt-in.a libtree.a
	${CC} -g -Wextra -Wall teste.c libft.a libbuilt-in.a libtree.a ${HEADER} -o tester
	
clean:
	${RM} *.o
	${RM} tester
	${MAKE} -C ./built-ins/ clean
	${MAKE} -C ./tree/ clean

fclean: clean
	${RM} minishell
	${RM} libbuilt-in.a
	${RM} libtree.a
	

re: fclean all

 .PHONY:linux test