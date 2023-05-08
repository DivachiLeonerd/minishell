/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirectto_mypipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:00:45 by afonso            #+#    #+#             */
/*   Updated: 2023/05/08 18:56:57 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

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

void	redirections_handler(int tokentype, t_tree *node)
{
	int fd;

	if (tokentype == I_REDIR)
		input_redirection(fd, node, tokentype);
	if (tokentype == O_REDIR || tokentype == APPEND)
		output_redirection(fd, node, tokentype);
	return ;
}
