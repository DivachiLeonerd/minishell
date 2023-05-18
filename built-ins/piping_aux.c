/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:47:06 by afonso            #+#    #+#             */
/*   Updated: 2023/05/17 18:30:42 by atereso-         ###   ########.fr       */
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
	{
		// perror("U r builtin");
		execute_builtin((node->args)[0], node->args);
		return (0);
	}
	else if (node->tokentype == EXECUTABLE)
	{
		// perror("im exec");
		execute_non_builtin((node->args)[0], node->args);
		return(127);
	}
	return (0);
}

char	**make_processes(t_tree *bintree)
{
	int		numof_pipes;
	int		pid;
	int		fd1;
	int		fd0;
	int		**pipe_fd;
	t_tree 	*node;

	pid = -1;
	numof_pipes = how_many_pipes(bintree);
	node = find_command_node(0, bintree);
	//check if the one command is a builtin and if it is, just run it
	if (numof_pipes == 0 && COMMAND)
	{
		fd1 = dup(STDOUT_FILENO);
		fd0 = dup(STDIN_FILENO);
		g_struct.myenvp = run_single_builtin(node);
		dup2(fd1, STDOUT_FILENO);
		dup2(fd0, STDIN_FILENO);
		return (g_struct.myenvp);
	}
 
	pid = fork();
	if (pid == 0)
	{
		pipe_fd = malloc(2 * sizeof(int *));
		pipe_fd[0] = malloc(2 * sizeof(int));
		pipe_fd[1] = malloc(2 * sizeof(int));
		multiple_processes(0, bintree, pipe_fd);
		exit(0);
	}
	else
	{
		// printf("im main()\n");
		waitpid(pid, NULL, 0);
		// printf("main()isn't waiting anymore\n");
	}
	return (g_struct.myenvp);
}
