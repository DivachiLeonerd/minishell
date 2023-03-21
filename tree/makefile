# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 12:24:32 by afonso            #+#    #+#              #
#    Updated: 2023/03/06 15:52:08 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libtree.a
HEADER := -I./ -I../built-ins -I../
LIB:= -L./built-ins -lbuilt-in -L../ -lft
TREE_OBJS:= heredoc.o  tree_building.o tree_building_cond.o tree_utils.o
CC := cc
CFLAGS := -g -Wall -Wextra -Werror #-fsanitize=address
RM := rm -f

all: ${NAME}

${NAME}: ${TREE_OBJS}
	ar -rcs ${NAME} ${TREE_OBJS}

clean:
	${RM} *.o