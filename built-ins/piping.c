/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:43:55 by afonso            #+#    #+#             */
/*   Updated: 2023/03/27 23:06:58 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piping.h"

//function that creates all pipes and returns the int**

int **pipe_creation(int how_many_pipes)
{
	int **pipe_fd;
	int i;

	i = 0;
	pipe_fd = malloc(how_many_pipes * sizeof(int *));
	while (pipe_fd && i < how_many_pipes)
	{
		pipe_fd[i] = malloc(2 * sizeof(int));
		pipe(pipe_fd[i]);
		i++;
	}
	return (pipe_fd);
}

int output_redirection(int fd1, t_tree *node, int token_type)
{
	char buf[200];
	int fd2;
	ssize_t readbytes;
	if (token_type == O_REDIR)
		fd2 = open(node->args[0] /*filename*/, O_CREAT, O_WRONLY);
	else if (token_type == O_APPEND)
		fd2 = open(node->args[0], O_CREAT, O_WRONLY, O_APPEND);
	else
		perror("Token type was neither redirect nor append");
	readbytes = read(fd1, buf, INT32_MAX);
	if (readbytes == -1)
	{
		perror("Failed read() instruction in redirection");
		return (-1);
	}
	write(fd2, buf, readbytes);
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
	printf("node:%p vs bintree:%p\n", node, bintree);
	while (node != bintree && i < index)
	{
		if (COMMAND)
			i++;
		else if (PIPE)
		{
			if (node->right_branch->tokentype == BUILTIN
				|| node->right_branch->tokentype == EXECUTABLE)
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