/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:19:45 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/08 21:23:17 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	make_child(t_tree *node, int **pipe_fd, int command_num, t_tree *bintree)
{
	int	pid;

	if (node->back->right_branch == node && node->back->back || command_num == 0)// what if command is in rightbranch
	{
		pipe(pipe_fd[0]);
		pid = fork();
	}
	if (pid == -1)
		perror("You are unforkable\n");
	if (pid == 0)
	{
		pipe_fd[1][0] = pipe_fd[0][0];
		pipe_fd[1][1] = pipe_fd[0][1];
		multiple_processes(++command_num, bintree);
	}
	return (pid);
}


static int	ft_child(t_tree *node, int command_num, t_tree *bintree, int **pipe_fd)
{
	t_tree **aux;
	int		ret;
	//process instructions here
	dup_iostream(pipe_fd, command_num, node);
	aux = node;
	while (node->right_branch)
	{
		node = node->right_branch;
		if (REDIR || node->tokentype == APPEND)
			redirections_handler(node->tokentype, node->args[0]);
		if (node->tokentype == HEREDOC)
			heredoc_handler(node->heredoc);
	}
	node = aux;
	ret = run_process(bintree, node, command_num);
	free_all_resources();
	//free stuff?
	return (ret);//command not found because we have tried everything
}

static void	ft_parent(int pid, int **pipe_fd)
{
	//dup2 all new fd's and close obsolete ones
	if (pipe_fd[0] > 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
	}
	if (pipe_fd[1] > 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}

	waitpid(pid, NULL, 0);
	return ;
}

void	multiple_processes(int command_num, t_tree *bintree)
{
	int	pid;
	int	pipe_fd[2][2];
	t_tree *command_node;
	
	command_node = find_command_node(command_num, bintree);	
	if (command_node)
	{
		pid = make_child(command_node, pipe_fd, command_num, bintree);
	}
	ft_child(command_node, command_num, bintree, pipe_fd);
	//the parent waits for the child before running
	ft_parent(pid, pipe_fd);
	return ;
}