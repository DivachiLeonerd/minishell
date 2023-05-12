/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:19:45 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/12 14:43:39 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	make_child(t_tree *node, int **pipe_fd, int command_num, t_tree *bintree, char **myenvp)
{
	int	pid;

	if ((node->back && node->back->right_branch == node && node->back->back) || command_num == 0)
	{
		pipe(pipe_fd[0]);
		pid = fork();
	}
	if (pid == -1)
		perror("You are unforkable\n");
	if (pid == 0 || (node->back->back == NULL && command_num != 0))
	{
		pipe_fd[1][0] = pipe_fd[0][0];
		pipe_fd[1][1] = pipe_fd[0][1];
		if (pid == 0)
			multiple_processes(++command_num, bintree, myenvp, pipe_fd);
	}
	return (pid);
}


static int	ft_child(t_tree *node, int command_num, int **pipe_fd, char **myenvp)
{
	t_tree *aux;
	int		ret;
	//process instructions here
	dup_iostream(pipe_fd, command_num, node);
	aux = node;
	while (node->right_branch)
	{
		node = node->right_branch;
		if (REDIR || node->tokentype == APPEND)
			redirections_handler(node);
		if (node->tokentype == HEREDOC)
			heredoc_handler(node->heredoc);
	}
	node = aux;
	ret = run_processes(node, myenvp);
	return (ret);//command not found because we have tried everything
}

static void	ft_parent(int pid, int **pipe_fd)
{
	close(STDOUT_FILENO);
	close(STDIN_FILENO);
	waitpid(pid, NULL, 0);
	free_all_resources(pipe_fd);
	exit(0);
}

void	multiple_processes(int command_num, t_tree *bintree, char **myenvp, int **pipe_fd)
{
	int	pid;
	t_tree *command_node;
	
	command_node = find_command_node(command_num, bintree);	
	if (command_node)
	{
		// I have to put these conditions inside a function like: is_forkable()
		if ((command_node->back && command_node->back->left_branch == command_node) || (command_node == command_node->back->right_branch && command_node->back->back))
			pid = make_child(command_node, pipe_fd, command_num, bintree, myenvp);
	}
	ft_child(command_node, command_num, pipe_fd, myenvp);
	ft_parent(pid, pipe_fd);
	return ;
}