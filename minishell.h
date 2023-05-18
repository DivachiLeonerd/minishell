/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:19:15 by afonso            #+#    #+#             */
/*   Updated: 2023/05/18 11:56:22 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <curses.h>
# include <term.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>
# include "./libft/libft.h"
# include "./tree/parser.h"
# include "./built-ins/built-ins.h"
# include "./built-ins/piping.h"
# include "define.h"

typedef struct g_controller
{
	int		chad_exitstatus;
	char	**myenvp;
}g_controller;

extern g_controller g_struct;

char	*print_prompt(int flag);
void	free_all_resources(int **pipe_fd);
#endif