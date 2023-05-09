/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirectto_mypipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:00:45 by afonso            #+#    #+#             */
/*   Updated: 2023/05/09 15:08:21 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dup_iostream(int **pipe_fd, int command_num, t_tree *node)
{
	
	if (command_num == 0)
	{
		close(pipe_fd[0][0]);
		dup2(pipe_fd[0][1], STDOUT_FILENO);
		close(pipe_fd[0][1]);
	}
	else if (node->back->back == NULL)
	{
		close(pipe_fd[1][1]);
		dup2(pipe_fd[1][0], STDIN_FILENO);
		close(pipe_fd[1][0]);
	}
	else
	{
		close(pipe_fd[0][0]);
		dup2(pipe_fd[0][1], STDOUT_FILENO);
		close(pipe_fd[0][1]);
		dup2(pipe_fd[1][0], STDIN_FILENO);
		close(pipe_fd[1][0]);
		close(pipe_fd[1][1]);
	}
	return ;
}

static int	output_redirection(int fd, t_tree *node, int token_type)
{
	if (token_type == O_REDIR)
		fd = open(node->args[0] /*filename*/, O_CREAT | O_WRONLY);
	else if (token_type == O_APPEND)
		fd = open(node->args[0], O_CREAT  | O_WRONLY | O_APPEND);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static int	input_redirection(int fd, t_tree *node, int token_type)
{
	if (token_type == I_REDIR)
		fd = open(node->args[0] /*filename*/, O_CREAT | O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

void	redirections_handler(int **pipe_fd, int tokentype, t_tree *node)
{
	if (tokentype == I_REDIR)
		input_redirection(pipe_fd[1][0], node, tokentype);
	if (tokentype == O_REDIR || tokentype == APPEND)
		output_redirection(pipe_fd[0][1], node, tokentype);
	return ;
}
