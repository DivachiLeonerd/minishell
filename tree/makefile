# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 12:24:32 by afonso            #+#    #+#              #
#    Updated: 2023/03/24 11:37:55 by atereso-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libtree.a
HEADER := -I./ -I../ -I../
LIB:= -L./built-ins -lbuilt-in -L../ -lft
TREE_OBJS:= parser_init.o parser_utils.o token_expander.o token_manager.o token_updater.o syntax_error_beta.o heredoc.o  tree_building.o tree_building_cond.o tree_utils.o
CC := cc
CFLAGS := -g -Wall -Wextra -Werror #-fsanitize=address
RM := rm -f

all: ${NAME}

${NAME}: ${TREE_OBJS}
	ar -rcs ${NAME} ${TREE_OBJS}

clean:
	${RM} *.o