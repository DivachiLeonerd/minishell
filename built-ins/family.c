/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:19:45 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/02 18:18:30 by atereso-         ###   ########.fr       */
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

void	ft_child(t_tree *node, int command_num, t_tree *bintree)
{
	int	pid;
	int pipe_fd[2][2];
	//process instructions here
	if (node->back && node->back->tokentype == PIPE)
		pipe(pipe_fd[0]);
	if (node->back && node->back->tokentype == PIPE)
	{
		if (node->back->left_branch == node)
			node = node->back->right_branch;
		else if (node->back->right_branch == node)
			node = node->back->back->right_branch;
		multiple_processes(++command_num, bintree);
	}
	return ;
}

void	ft_parent(int pid)
{
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
		pid = make_child(command_node);
	if (pid == 0)
		ft_child(command_node, command_num,bintree);
	//the parent waits for the child before running
	else
		ft_parent(pid);
	return ;
}