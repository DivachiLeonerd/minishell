/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:47:06 by afonso            #+#    #+#             */
/*   Updated: 2023/04/03 18:22:41 by atereso-         ###   ########.fr       */
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
		free(pipe_fd[i]);
		i--;
	}
	free(pid);
	// free(pipe_fd);
	return ;
}

char	**run_pipes(int numof_pipes, t_tree *bintree, int *pid, char ***myenvp)
{
	int	i;
	t_tree *node;

	i = 0;
	while (i <= numof_pipes)
	{
		node = find_command_node(i, bintree);//command index is the position of each command in command line
		if (pid[0] != 0 && ft_strncmp((node->args)[0], "cd", 3) == 0)
			*myenvp = cd((node->args)[1], *myenvp);
		if (pid[0] != 0 && ft_strncmp((node->args)[0], "export", 7) == 0)
			*myenvp = export(&((node->args)[1]), *myenvp);
		if (pid[0] != 0 && ft_strncmp((node->args)[0], "unset", 6) == 0)
			*myenvp = unset(&((node->args)[1]), *myenvp);
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
			if (is_builtin((node->args)[0]))
				execute_builtin((node->args)[0], *myenvp, node->args);
			else
				execute_non_builtin((node->args)[0], *myenvp, node->args);
			// waitpid(pid[i - 1], NULL, 0);
		}
		i++;
	}
	i = 0;
	
	while (i <= numof_pipes && pid[i] == 0)
	{
		exit(0);
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
	printf("in make_pipes():numof_pipes:%d\n", numof_pipes);
	pid = malloc((numof_pipes + 1) * sizeof(int));//if there is 3 processes then we will need only 2 pipes
	pipe_fd = pipe_creation(numof_pipes);
	initialize_forking_processes(pid, numof_pipes + 1);
	while (pipe_fd && i <= numof_pipes)
		piping(pid, pipe_fd, numof_pipes, i++);
	myenvp = run_pipes(numof_pipes, bintree, pid, &myenvp);
	waitpid(pid[0],NULL,0);
	free_utils(pid, pipe_fd, numof_pipes);
	return (myenvp);
}