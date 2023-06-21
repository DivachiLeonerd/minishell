/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:43:55 by afonso            #+#    #+#             */
/*   Updated: 2023/06/02 18:27:22 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piping.h"
#include "../minishell.h"

int	**pipe_creation(int how_many_pipes)
{
	int	**pipe_fd;
	int	i;

	i = 0;
	if (!how_many_pipes)
		return (NULL);
	pipe_fd = malloc(how_many_pipes * sizeof(int *));
	while (pipe_fd && i < how_many_pipes)
	{
		pipe_fd[i] = malloc(2 * sizeof(int));
		pipe(pipe_fd[i]);
		i++;
	}
	return (pipe_fd);
}

int	piping(int *pid, int **pipe_fd, int num_of_pipes, int index)
{
	if (num_of_pipes == 0)
		return (0);
	if (index <= num_of_pipes && pid[index] == 0)
	{
		if (index > 0)
			dup2(pipe_fd[index - 1][0], STDIN_FILENO);
		if (index < num_of_pipes)
			dup2(pipe_fd[index][1], STDOUT_FILENO);
	}
	return (0);
}

t_tree	*check_right_branch(t_tree *node, int *i, int index)
{
	if (node->right_branch)
	{
		if (node->right_branch->tokentype == BUILTIN
			|| node->right_branch->tokentype == EXECUTABLE)
		{
			(*i)++;
			if (*i == index)
				return (node->right_branch);
		}
	}
	g_struct.chad_exitstatus = 127;
	return (NULL);
}

t_tree	*find_command_node(int index, t_tree *bintree)
{
	int		i;
	t_tree	*node;

	i = -1;
	node = find_first_command(bintree);
	while (i < index)
	{
		if ((node->tokentype == BUILTIN || node->tokentype == EXECUTABLE))
			i++;
		else if (PIPE)
			return (check_right_branch(node, &i, index));
		if (node->back != NULL && i < index)
			node = node->back;
	}
	return (node);
}

void	initialize_forking_processes(int *pid, int numof_processes)
{
	int	i;

	i = numof_processes - 1;
	while (0 <= i)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			exit(-1);
		if (pid[i] == 0)
			break ;
		i--;
	}
	return ;
}
