/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:47:06 by afonso            #+#    #+#             */
/*   Updated: 2023/04/16 14:04:51 by atereso-         ###   ########.fr       */
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

static void	wait_for_children(int *pid, int numof_pipes)
{
	int	i;

	i = 0;
	if (numof_pipes == 0)
		wait(NULL);
	else
		while (i < numof_pipes)
		{
			waitpid(pid[i], NULL, 0);
			kill(pid[i + 1], SIGQUIT);
			i++;
			if (pid[i] == 0)
				exit(0);
		}
	free(pid);
	return ;
}

static void	free_utils(int **pipe_fd, int numof_pipes)
{
	int	i;

	i = numof_pipes - 1;
	while (pipe_fd && i >= 0)
	{
		close(pipe_fd[i][0]);
		free(pipe_fd[i]);
		i--;
	}
	free(pipe_fd);
	i = numof_pipes - 1;
	return ;
}

char	**run_pipes(int numof_pipes, t_tree *bintree, int *pid,
			char ***myenvp)
{
	int	i;
	t_tree *node;

	i = 0;
	while (i <= numof_pipes)
	{
		node = find_command_node(i, bintree);//command index is the position of each command in command line
		if (pid[i] == 0)
		{
			if (return_righttokenid(node) == O_REDIR)
				output_redirection(STDOUT_FILENO, node->right_branch, O_REDIR);
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
		}
		i++;
	}
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
	pid = malloc((numof_pipes + 1) * sizeof(int));//if there is 3 processes then we will need only 2 pipes
	pipe_fd = pipe_creation(numof_pipes);
	initialize_forking_processes(pid, numof_pipes + 1);
	while (pipe_fd && i <= numof_pipes)
		piping(pid, pipe_fd, numof_pipes, i++);
	myenvp = run_pipes(numof_pipes, bintree, pid, &myenvp);
	free_utils(pipe_fd, numof_pipes);
	while (i < numof_pipes || i == 0)
	{
		if (pid[i] == 0)
			exit(0);
		i++;
	}
	wait_for_children(pid, numof_pipes);
	return (myenvp);
}