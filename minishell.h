/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:19:15 by afonso            #+#    #+#             */
/*   Updated: 2023/02/22 14:59:19 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <termcap.h>
#include "libft.h"

#define I_REDIR 0
#define O_REDIR 1
#define PIPE 2
#define HEREDOC 3
#define APPEND 4
#define BUILTIN 5
#define EXECUTABLE 6
#define COMMAND (node->tokentype == BUILTIN || node->tokentype == EXECUTABLE)
#define REDIR (node->tokentype == 0 || node->tokentype == 1)

typedef struct s_tree
{
int				tokentype;
char			**args;
struct s_tree	*left_branch;
struct s_tree	*right_branch;
struct s_tree	*back;
}t_tree;

#endif
