/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:19:45 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/09 18:28:36 by atereso-         ###   ########.fr       */
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
	if (pid == 0)
	{
		pipe_fd[1][0] = pipe_fd[0][0];
		pipe_fd[1][1] = pipe_fd[0][1];
		multiple_processes(++command_num, bintree, myenvp);
	}
	return (pid);
}


static int	ft_child(t_tree *node, int command_num, int **pipe_fd, char **myenvp)
{
	t_tree *aux;
	int		ret;
	//process instructions here
	printf("Hello There! My name is %s\n", node->args[0]);
	dup_iostream(pipe_fd, command_num, node);
	aux = node;
	while (node->right_branch)
	{
		node = node->right_branch;
		if (REDIR || node->tokentype == APPEND)
			redirections_handler(pipe_fd, node->tokentype, node);
		if (node->tokentype == HEREDOC)
			heredoc_handler(node->heredoc);
	}
	node = aux;
	ret = run_processes(node, myenvp);
	printf("ret is %d\n", ret);
	// free_all_resources(myenvp, bintree, pipe_fd);
	return (ret);//command not found because we have tried everything
}

static void	ft_parent(int pid, char **myenvp, t_tree *bintree, int **pipe_fd)
{
	perror("im in parent");
	waitpid(pid, NULL, 0);
	free_all_resources(myenvp, bintree, pipe_fd);
	return ;
}

void	multiple_processes(int command_num, t_tree *bintree, char **myenvp)
{
	int	pid;
	int	**pipe_fd;
	// int **pipe_ptr;
	pipe_fd = malloc(2 * sizeof(int *));
	pipe_fd[0] = malloc(2 * sizeof(int));
	pipe_fd[1] = malloc(2 * sizeof(int));
	// pipe_ptr = pipe_fd;
	t_tree *command_node;
	
	command_node = find_command_node(command_num, bintree);	
	if (command_node)
	{
		printf("going for make_child()\n");
		pid = make_child(command_node, pipe_fd, command_num, bintree, myenvp);
		printf("exTITed make_child()\n");
	}
	ft_child(command_node, command_num, pipe_fd, myenvp);
	//the parent waits for the child before running
	ft_parent(pid,myenvp, bintree, pipe_fd);
	return ;
}