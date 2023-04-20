/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:28:54 by afonso            #+#    #+#             */
/*   Updated: 2023/04/20 19:39:54 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef DEFINE_H
#define DEFINE_H

typedef struct s_heredoc
{
	int				pipe_fd[2];
	char			*delimiter;
	ssize_t			bytes_stored;
}t_heredoc;

typedef struct s_tree
{
int				tokentype;
char			**args;
t_heredoc		*heredoc;
struct s_tree	*left_branch;
struct s_tree	*right_branch;
struct s_tree	*back;
}t_tree;


#define I_REDIR 1
#define O_REDIR 2
#define PIPE 3
#define HEREDOC 4
#define APPEND 5
#define BUILTIN 6
#define EXECUTABLE 7
#define WORD 8
#define NODE_WORTHY tokentype != WORD
#define PROMPT "GigaShell:"
#define COMMAND (node->tokentype == BUILTIN || node->tokentype == EXECUTABLE)
#define REDIR (node->tokentype == I_REDIR || node->tokentype == O_REDIR)

void	free_matrix(char **envp);
char	*find_command_path(char **myenvp, char *command);
#endif
extern int	chad_exitstatus;