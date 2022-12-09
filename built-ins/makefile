# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 10:45:02 by afonso            #+#    #+#              #
#    Updated: 2022/12/09 11:31:08 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libbuilt-in.a
HEADER := -I./ -I../
OBJDIR:= ./Objects
BIOBJDIR:= ./built-in_objs/
ALL_OBJS:= ${ECHO_OBJS} ${CD_OBJS} ${PWD_OBJS} ${FTEXPORT_OBJS} ${UNSET_OBJS} ${ENV_OBJS} ${EXIT_OBJS}
ECHO_OBJS:=
PWD_OBJS:=
CD_OBJS:=
FTEXPORT_OBJS:=
UNSET_OBJS:=
ENV_OBJS:=
EXIT_OBJS:=
CC := gcc
CFLAGS := -g -Wall -Wextra -Werror #-fsanitize=address
RM := rm -f

mv_objs: libbuilt.a
	mv *.o ../built-in_objs/
	mv libbuilt-in.a ../

libbuilt-in.a: all

all: echo cd pwd ftexport unset env exit
	cd built-in_objs && ${CC} ${CFLAGS} ${ALL_OBJS} -o ${NAME}

ftecho: ${ECHO_OBJS}
	mv *.o ../built-in_objs

ftcd: ${CD_OBJS}
	mv *.o ../built-in_objs

ftpwd: ${PWD_OBJS}
	mv *.o ../built-in_objs

ftexport: ${FTEXPORT_OBJS}
	mv *.o ../built-in_objs

ftunset: ${UNSET_OBJS}
	mv *.o ../built-in_objs

ftenv: ${ENV_OBJS}
	mv *.o ../built-in_objs

ftexit: ${EXIT_OBJS}
	mv *.o ../built-in_objs

clean:
	cd built-in_objs && rm -rf *.o

.PHONY: ftecho, ftpwd, ftexport, ftunset, ftenv, ftexit