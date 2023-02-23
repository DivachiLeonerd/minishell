/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:43:55 by afonso            #+#    #+#             */
/*   Updated: 2023/02/23 11:21:32 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

// I need a function that creates all pipes and returns the int**

int **pipe_creation(int how_many_pipes)
{
	int **pipe_fd;
	int i;

	i = 0;
	pipe_fd = malloc(how_many_pipes * sizeof(int *));
	while (i < how_many_pipes)
	{

		pipe_fd[i] = malloc(2 * sizeof(int));
		pipe(pipe_fd[i]);
		i++;
	}
	return (pipe_fd);
}

int output_redirection(int fd1, t_tree *node)
{
	char buf[INT32_MAX];
	int fd2;
	ssize_t readbytes;

	fd2 = open(node->args[0] /*filename*/, O_CREAT, O_WRONLY);
	readbytes = read(fd1, buf, INT32_MAX);
	if (readbytes == -1)
	{
		perror("Failed read() instruction in redirection");
		return (-1);
	}
	write(fd2, buf, ft_strlen(buf));
	close(fd2);
	return (0);
}

int	piping(int *pid, int **pipe_fd, int num_of_pipes, int index)
{
	if (pid[index] == 0)
	{
		if (index > 0)
			dup2(pipe_fd[index - 1][0], STDIN_FILENO); // STDIN of a i process is the read part of pipe connecting it to process i - 1
		if (index < num_of_pipes)
			dup2(pipe_fd[index][1], STDOUT_FILENO); // process is writing to pipe instead of stdout
		// I need to do error checking
	}
	return (0);
}

t_tree *find_command_node(int index, t_tree *bintree)
{
	int i;
	t_tree *node;

	i = -1;
	node = find_first_command(bintree);
	while (node != bintree && i < index)
	{
		if (COMMAND)
			i++;
		else if (PIPE)
		{
			if (node->right_branch->tokentype == 5
				|| node->right_branch->tokentype == 6)
			{
				i++;
				if (i == index)
					return (node->right_branch);
			}
		}
		node = node->back;
	}
	return (node);
}

void initialize_forking_processes(int *pid, int numof_processes)
{
	int i;

	i = 0;
	while (i < numof_processes)
	{
		if ((pid[i] = fork()) == -1)
			perror("A problem has occured during fork process\n");
		i++;
	}
	return;
}