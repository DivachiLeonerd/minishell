# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 10:45:02 by afonso            #+#    #+#              #
#    Updated: 2023/03/06 12:15:57 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libbuilt-in.a
HEADER := -I../ -I../../ -I./
LIB:= -L./ -lbuilt-in -L../ -lft 
OBJDIR:= ./Objects
BIOBJDIR:= ./built-in_objs/
ALL_OBJS:= echo.o pwd.o cd.o export.o unset.o env.o
ECHO_OBJS:=./echo/echo.o
PWD_OBJS:=./pwd/pwd.o
CD_OBJS:=./cd/cd.o
FTEXPORT_OBJS:=./export/export.o
UNSET_OBJS:=./unset/unset.o
ENV_OBJS:=./env/env.o
EXIT_OBJS:=./exit/exit.o
BUILTIN_HELPER:= built-in_helper.o executer.o not_built-in_exec.o realloc_env_aux.o piping.o piping_aux.o redirections.o redirectto_mypipe.o
CC := cc
CFLAGS := -g -Wall -Wextra -Werror #-fsanitize=address
RM := rm -f

all: libbuilt-in.a
	mv built-in_objs/${NAME} ./

${NAME}: ftecho ftcd ftpwd ftexport ftunset ftenv  fthelper all #ftexit
	cd built-in_objs && ar rcs ${NAME} ${ALL_OBJS} ${BUILTIN_HELPER}

testb: all
	${CC}  tester.c -g -fsanitize=address ${HEADER} ${LIB} -o tester

ftecho:
	${CC} ${CFLAGS} echo/echo.c ${HEADER} ${LIB} -c
	mv echo.o ./built-in_objs

ftcd:
	${CC} ${CFLAGS} cd/cd.c ${HEADER} ${LIB} -c
	mv cd.o ./built-in_objs

ftpwd:
	${CC} ${CFLAGS} pwd/pwd.c ${HEADER} ${LIB} -c
	mv pwd.o ./built-in_objs

ftexport:
	${CC} ${CFLAGS} export/export.c ${HEADER} ${LIB} -c
	mv export.o ./built-in_objs

ftunset:
	${CC} ${CFLAGS} unset/unset.c ${HEADER} ${LIB} -c
	mv unset.o ./built-in_objs

ftenv:
	${CC} ${CFLAGS} env/env.c ${HEADER} ${LIB} -c
	mv env.o ./built-in_objs

ftexit:
	${CC} ${CFLAGS} exit/exit.c ${HEADER} ${LIB} -c
	mv exit/exit.o ./built-in_objs

fthelper: 
	${CC} ${CFLAGS} not_built-in_exec.c realloc_env_aux.c executer.c built-in_helper.c piping.c piping_aux.c redirections.c redirectto_mypipe.c ${HEADER} ${LIB} -c
	mv *.o ./built-in_objs

clean:
	cd built-in_objs && rm -rf *.o
	

fclean:clean
	${RM} libbuilt-in.a
	${RM} tester
	${RM} *.out
.PHONY: ftecho, ftpwd, ftexport, ftunset, ftenv, ftexit, clean