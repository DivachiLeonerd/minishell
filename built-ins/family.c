/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:19:45 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/02 22:22:14 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	make_child(t_tree *node)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		perror("You are unforkable\n");
	return (pid);
}

void	ft_child(t_tree *node, int command_num, t_tree *bintree, int **pipe_fd)
{
	int	pid;
	if (command_num > 0)
	{
		pipe_fd[0][0] = dup(pipe_fd[1][0]);
		pipe(pipe_fd[1]);
	}
	if (node->back && node->back->tokentype == PIPE)
	{
		pipe(pipe_fd[1]);
		close(pipe_fd[1][0]);
		multiple_processes(++command_num, bintree);
	}
	//process instructions here
	run_process();
	exit(127);//command not found because we have tried everything
}

void	ft_parent(int pid, int **pipe_fd)
{
	//dup2
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
		pid = make_child(command_node);
	}
	if (pid == 0)
	{
		
		ft_child(command_node, command_num, bintree, pipe_fd);
	}
	//the parent waits for the child before running
	else
	{
		ft_parent(pid, pipe_fd);
	}
	return ;
}