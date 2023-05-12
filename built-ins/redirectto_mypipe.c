/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirectto_mypipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:00:45 by afonso            #+#    #+#             */
/*   Updated: 2023/05/12 17:51:44 by atereso-         ###   ########.fr       */
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
	perror("output redir");
	if (node->tokentype == O_REDIR)
		fd = open(node->args[0] /*filename*/, O_CREAT | O_WRONLY);
	else if (node->tokentype == APPEND)
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

void	redirections_handler(t_tree *node)
{
	t_tree *aux;

	aux = node;
	printf("redirects happening\n");
	while (aux->right_branch)
	{
		aux = aux->right_branch;
		printf("right_branch_tk:%d\n", node->tokentype);
		if (aux->tokentype == I_REDIR)
			input_redirection(STDIN_FILENO, aux, aux->tokentype);
		if (aux->tokentype == O_REDIR || aux->tokentype == APPEND)
			output_redirection(STDOUT_FILENO, aux);
	}
	return ;
}
