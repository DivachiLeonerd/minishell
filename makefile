# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 15:45:01 by afonso            #+#    #+#              #
#    Updated: 2023/03/24 12:16:52 by atereso-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell
HEADER := -I./ -I./ -I./built-ins/ -I/libft/ -I./tree/
LIB := -L./ -ltree -lbuilt-in -lft -lreadline
OBJDIR:= ./Objects
BIOBJ:= ./built-ins/built-in_objs
OBJS:= 
OBJS_built-in:=
#OBJS_T :=
CC := cc
CFLAGS := -g -fsanitize=address #-Wall -Wextra -Werror 
RM := rm -f

all:minishell

libft.a:
	${MAKE} -C ./libft/ all && cd ./libft && mv libft.a ../

libbuilt-in.a:
	${MAKE} -C ./built-ins all && cd ./built-ins && mv libbuilt-in.a ../

libtree.a:
	${MAKE} -C ./tree all && cd ./tree && mv libtree.a ../
	
minishell: built-in tree
	${CC} ${CFLAGS} ${NAME}.c ${OBJS} ${HEADER} -o ${NAME}
	mv *.o ./Objects

test: libbuilt-in.a libtree.a libft.a
	${CC} ${CFLAGS} teste.c ${LIB} ${HEADER} -o minitester
	
clean:
	${RM} *.o
	${MAKE} -C ./built-ins/ clean
	${MAKE} -C ./tree/ clean
	${MAKE} -C ./libft/ clean

fclean: clean
	${RM} minishell
	${RM} minitester
	${RM} *.a

re: fclean test
	make clean

 .PHONY:linux test fclean clean re