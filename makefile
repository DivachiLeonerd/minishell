# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 15:45:01 by afonso            #+#    #+#              #
#    Updated: 2023/05/09 16:13:47 by atereso-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell
HEADER := -I./ -I./ -I./built-ins/ -I/libft/ -I./tree/
LIB := -L./ -ltree -lbuilt-in -lft -lreadline
OBJDIR:= ./Objects
BIOBJ:= ./built-ins/built-in_objs
OBJS:= free_all_resources.o run_single_builtin.o
OBJS_built-in:=
#OBJS_T :=
CC := cc
CFLAGS := -g -Wall -Wextra -Werror -fsanitize=address
RM := rm -f

all: minishell
	printf("Its done")
libft.a:
	@${MAKE} -C ./libft/ all && cd ./libft && mv libft.a ../

libbuilt-in.a:
	@${MAKE} -C ./built-ins all && cd ./built-ins && mv libbuilt-in.a ../

libtree.a:
	@${MAKE} -C ./tree all && cd ./tree && mv libtree.a ../
	
minishell: built-in tree
	@${CC} ${CFLAGS} ${NAME}.c ${OBJS} ${HEADER} -o ${NAME}
	@mv *.o ./Objects

test: ${OBJS} libbuilt-in.a libtree.a libft.a
	@${CC} ${CFLAGS} teste.c ${LIB} ${HEADER} ${OBJS} -o minitester
	
clean:
	@${RM} *.o
	@${MAKE} -C ./built-ins/ clean
	@${MAKE} -C ./tree/ clean
	@${MAKE} -C ./libft/ clean

fclean: clean
	@${RM} minishell
	@${RM} minitester
	@${RM} *.a

re: fclean test
	${MAKE} -s clean
	printf "Its done\n"

 .PHONY:linux test fclean clean re