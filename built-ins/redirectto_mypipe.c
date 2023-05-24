/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirectto_mypipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:00:45 by afonso            #+#    #+#             */
/*   Updated: 2023/05/23 17:29:21 by atereso-         ###   ########.fr       */
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

static int	output_redirection(int fd, t_tree *node)
{
	if (node->tokentype == O_REDIR)
		fd = open(node->args[0], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (node->tokentype == APPEND)
		fd = open(node->args[0], O_CREAT | O_WRONLY | O_APPEND, 0666);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static int	input_redirection(int fd, t_tree *node)
{
	if (node->tokentype == I_REDIR)
		fd = open(node->args[0], O_CREAT | O_RDONLY, 0666);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

void	redirections_handler(t_tree *node)
{
	t_tree	*aux;

	aux = node;
	while (aux->right_branch)
	{
		aux = aux->right_branch;
		if (aux->tokentype == I_REDIR)
			input_redirection(STDIN_FILENO, aux);
		if (aux->tokentype == O_REDIR || aux->tokentype == APPEND)
			output_redirection(STDOUT_FILENO, aux);
		if (aux->tokentype == HEREDOC)
			heredoc_handler(aux->heredoc);
	}
	return ;
}
