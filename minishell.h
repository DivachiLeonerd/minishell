/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:19:15 by afonso            #+#    #+#             */
/*   Updated: 2022/12/12 15:00:42 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_tree
{
    void *token;
    int type;
    
}