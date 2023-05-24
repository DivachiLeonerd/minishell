# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 15:45:01 by afonso            #+#    #+#              #
#    Updated: 2023/05/23 10:40:15 by atereso-         ###   ########.fr        #
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
CFLAGS := -g -Wall -Wextra -Werror  -ggdb -fsanitize=address
RM := rm -f

all: ${NAME}
	printf "Its done\n"

${NAME}: ${OBJS} libbuilt-in.a libtree.a libft.a
	@${CC} ${CFLAGS} teste.c ${LIB} ${HEADER} ${OBJS} -o ${NAME}
	mkdir -p Objects
	@mv *.o ./Objects/
	${MAKE} -s clean

libft.a:
	@${MAKE} -C ./libft/ all && cd ./libft && mv libft.a ../

libbuilt-in.a:
	@${MAKE} -C ./built-ins all && cd ./built-ins && mv libbuilt-in.a ../

libtree.a:
	@${MAKE} -C ./tree all && cd ./tree && mv libtree.a ../

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

 .PHONY:all test fclean clean re libtree.a libbuilt-in.a libft.a