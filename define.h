/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:28:54 by afonso            #+#    #+#             */
/*   Updated: 2023/02/23 17:00:25 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
#define DEFINE_H

typedef struct s_tree
{
int				tokentype;
char			**args;
struct s_tree	*left_branch;
struct s_tree	*right_branch;
struct s_tree	*back;
}t_tree;

typedef struct s_heredoc
{
	int				index;//is it the first? second? last?
	int				pipe_fd[2];
	char			*delimiter;
}t_heredoc;

#define I_REDIR 0
#define O_REDIR 1
#define PIPE 2
#define HEREDOC 3
#define APPEND 4
#define BUILTIN 5
#define EXECUTABLE 6
#define COMMAND (node->tokentype == BUILTIN || node->tokentype == EXECUTABLE)
#define REDIR (node->tokentype == 0 || node->tokentype == 1)
#endif