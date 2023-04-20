/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:43:55 by afonso            #+#    #+#             */
/*   Updated: 2023/04/20 18:41:44 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piping.h"

//function that creates all pipes and returns the int**

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

int	output_redirection(int fd1, t_tree *node, int token_type)
{
	char	buf[200];
	int		fd2;
	ssize_t	readbytes;

	if (token_type == O_REDIR)
		fd2 = open(node->args[0] /*filename*/, O_CREAT, O_WRONLY);
	else if (token_type == O_APPEND)
		fd2 = open(node->args[0], O_CREAT, O_WRONLY, O_APPEND);
	else
		perror("Token type was neither redirect nor append");
	readbytes = read(fd1, buf, 200);
	if (readbytes == -1)
	{
		perror("Failed read() instruction in redirection");
		return (-1);
	}
	write(fd2, buf, readbytes);
	close(fd2);
	return (0);
}

// pipe_fd[0] is the read part of the pipe where u read FROM the pipe
//pipe_fd[1] is the write part of the pipe where u write TO the pipe
int	piping(int *pid, int **pipe_fd, int num_of_pipes, int index)
{
	if (num_of_pipes == 0)
		return (0);
	if (index <= num_of_pipes && pid[index] == 0)
	{
		// printf("in piping():I'm process %d. Im piping %d[0] to stdin and [index][1] to stdout\n", index, index);
		if (index > 0)
		{
			dup2(pipe_fd[index - 1][0], STDIN_FILENO); // STDIN of a i process is the read part of pipe connecting it to process i - 1
		}
		if (index < num_of_pipes)
		{
			dup2(pipe_fd[index][1], STDOUT_FILENO); // process is writing to pipe instead of stdout	
		}
		// I need to do error checking
	}
	return (0);
}

t_tree	*find_command_node(int index, t_tree *bintree)
{
	int		i;
	t_tree	*node;

	i = -1;
	node = find_first_command(bintree);
	while (i < index)
	{
		if (COMMAND)
			i++;
		else if (PIPE)
		{
			if (node->right_branch)
			{
				if (node->right_branch->tokentype == BUILTIN
					|| node->right_branch->tokentype == EXECUTABLE)
				{
					i++;
					if (i == index)
						return (node->right_branch);
				}
			}
			else
			{
				chad_exitstatus = 127;
				return (NULL);
			}
		}
		if (node->back != NULL && i < index)
			node = node->back;
	}
	return (node);
}

void	initialize_forking_processes(int *pid, int numof_processes)
{
	int	i;

	i = numof_processes - 1;
	// printf("numof_processes%d\n", numof_processes);
	while (0 <= i)
	{
		if ((pid[i] = fork()) == -1)
			perror("A problem has occured during fork process\n");
		if (pid[i] == 0)
			break ;
		i--;
	}
	return ;
}
