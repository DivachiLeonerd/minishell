/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:47:06 by afonso            #+#    #+#             */
/*   Updated: 2023/04/15 18:03:13 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	how_many_pipes(t_tree *bintree)
{
	int		numof_pipes;
	t_tree	*node;

	numof_pipes = 0;
	node = bintree;
	// printf("in how_many_pipes(): %p\n", node->left_branch);
	while (node->left_branch != NULL)
	{
		if (node->tokentype == PIPE)
			numof_pipes++;
		node = node->left_branch;
	}
	return (numof_pipes);
}

static void	free_utils(int *pid, int **pipe_fd, int numof_pipes)
{
	int	i;
	
	i = numof_pipes - 1;
	while (pipe_fd && i >= 0)
	{
		printf("free_tree()\n");
		close(pipe_fd[i][0]);
		free(pipe_fd[i]);
		i--;
	}
	free(pipe_fd);
	i = numof_pipes - 1;
	if (pid[0] == 0)
		exit (0);
	free(pid);
	return ;
}

char	**run_pipes(int numof_pipes, t_tree *bintree, int *pid, char ***myenvp, int **pipe_fd)
{
	int	i;
	// int	j;
	t_tree *node;

	i = 0;
	// j = -1;
	// printf("We are in run_pipes()\n");
	while (i <= numof_pipes)
	{
		node = find_command_node(i, bintree);//command index is the position of each command in command line
		if (pid[i] == 0)
		{
			// if (return_righttokenid(node) == O_REDIR)
			// 	output_redirection(STDOUT_FILENO, node->right_branch, O_REDIR);
			// if (return_righttokenid(node) == O_APPEND)
			// 	output_redirection(STDOUT_FILENO, node->right_branch, O_APPEND);
			// if (return_righttokenid(node) == I_REDIR)
			// 	input_redirection(STDIN_FILENO, node);
			// if (return_righttokenid(node) == HEREDOC)
			//heredoc?
			// j = i;
			if (is_builtin((node->args)[0]))
				execute_builtin((node->args)[0], *myenvp, node->args);
			else
				execute_non_builtin((node->args)[0], *myenvp, node->args);
			if (numof_pipes > 0 && i < numof_pipes)
			{
				close(pipe_fd[i][0]);
			}
		}
		i++;
	}
	waitpid(pid[0], NULL, 0);
	printf("child number 0 is waiting bruh\n");
	close(pipe_fd[0][1]);
	close(pipe_fd[0][0]);
	kill(pid[1], SIGQUIT);
	waitpid(pid[1], NULL, 0);
	printf("child number 1 is waiting bruh\n");
	return (*myenvp);
}

char	**make_pipes(t_tree *bintree, char **myenvp)
{
	int		i;
	int		numof_pipes;
	int		**pipe_fd;
	int		*pid;

	i = 0;
	numof_pipes = how_many_pipes(bintree);
	printf("in make_pipes():numof_pipes:%d\n", numof_pipes);
	pid = malloc((numof_pipes + 1) * sizeof(int));//if there is 3 processes then we will need only 2 pipes
	pipe_fd = pipe_creation(numof_pipes);
	initialize_forking_processes(pid, numof_pipes + 1);
	while (pipe_fd && i <= numof_pipes)
		piping(pid, pipe_fd, numof_pipes, i++);
	// printf("in make_pipes() we vibing\n");
	myenvp = run_pipes(numof_pipes, bintree, pid, &myenvp, pipe_fd);
	printf("after_make_pipes()\n");
	free_utils(pid, pipe_fd, numof_pipes);
	return (myenvp);
}