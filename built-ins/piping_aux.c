/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:47:06 by afonso            #+#    #+#             */
/*   Updated: 2023/06/02 18:14:53 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	how_many_pipes(t_tree *bintree)
{
	int		numof_pipes;
	t_tree	*node;

	numof_pipes = 0;
	node = bintree;
	while (node->left_branch != NULL)
	{
		if (node->tokentype == PIPE)
			numof_pipes++;
		node = node->left_branch;
	}
	return (numof_pipes);
}

int	run_processes(t_tree *node)
{
	if (node->tokentype == BUILTIN)
		return (execute_builtin((node->args)[0], node->args));
	else if (node->tokentype == EXECUTABLE)
		return (execute_non_builtin((node->args)[0], node->args));
	return (0);
}

static void	single_builtin(int *fd, t_tree *node)
{
	fd[1] = dup(STDOUT_FILENO);
	fd[0] = dup(STDIN_FILENO);
	g_struct.chad_exitstatus = run_single_builtin(node);
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	return ;
}

void	make_processes(t_tree *bintree)
{
	int		npipes;
	int		fd[2];
	int		pid;
	int		**pipe_fd;
	t_tree	*node;

	npipes = how_many_pipes(bintree);
	node = find_command_node(0, bintree);
	if (!npipes && (node->tokentype == BUILTIN
			|| node->tokentype == EXECUTABLE))
		return (single_builtin(fd, node));
	pid = fork();
	if (pid == 0)
	{
		pipe_fd = malloc(2 * sizeof(int *));
		pipe_fd[0] = malloc(2 * sizeof(int));
		pipe_fd[1] = malloc(2 * sizeof(int));
		multiple_processes(0, bintree, pipe_fd);
	}
	waitpid(pid, NULL, 0);
	return ;
}
