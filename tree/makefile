# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 12:24:32 by afonso            #+#    #+#              #
#    Updated: 2023/05/10 11:20:33 by atereso-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libtree.a
HEADER := -I./ -I../ -I../
LIB:= -L./built-ins -lbuilt-in -L../ -lft
TREE_SRC:= parser_init.c parser_utils.c token_expander.c token_manager.c token_updater.c syntax_error_beta.c heredoc.c  tree_building.c tree_building_cond.c tree_utils.c
CC := cc
OBJS := ${TREE_SRC:.c=.o}
CFLAGS := -g -Wall -Wextra -Werror -fsanitize=address
RM := rm -f

.SILENT:all

all: ${NAME}

${NAME}: ${OBJS}
	@ar -rcs ${NAME} ${OBJS}
.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${HEADER}

clean:
	@${RM} *.o