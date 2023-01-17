/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:04:42 by afonso            #+#    #+#             */
/*   Updated: 2023/01/15 17:43:46 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int fd1;
	int	fd2;
	int x;

	x = 0;
	pipe(pipe_fd);
	fd1 = fork();
	if (fd1 == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		x += 3;
		write(STDOUT_FILENO, &x, sizeof(int));
		close(pipe_fd[1]);
		close(fd2);
		return 0;
	}
	fd2 = fork();
	if (fd2 == 0)
	{
		close(pipe_fd[1]);
		read(pipe_fd[0], &x, sizeof(int));
		printf("%d\n", x);
		close(pipe_fd[0]);
		return 0;
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (0);
}

//Needs to be shortened by dividing into smaller functions
//Should be tested first though
void	make_and_run_pipes(void *bintree, char **myenvp)
{
	int	i;
	int	numof_pipes;
	int	**pipe_fd;
	int	*fd;

	i = 0;
	numof_pipes = how_many_pipes(bintree);
	pipe_fd = malloc(numof_pipes * sizeof(int *));
	fd = malloc((numof_pipes + 1) * sizeof(int));
	while (i < numof_pipes)
	{
		
		pipe_fd[i] = malloc(2 * sizeof(int));
		pipe(pipe_fd[i]);
		i++;
	}
	i = 0;
	while (i < numof_pipes)
	{
		fd[i] = fork();
		if (fd[i] == 0)
		{
			if (i > 0)
				dup2(pipe_fd[i - 1][0], STDIN_FILENO);//STDIN of a i process is the read part of pipe connecting it to process i - 1
			if (i < numof_pipes)
				dup2(pipe_fd[i][1], STDOUT_FILENO);//process is writing to pipe instead of stdout
			if (!is_builtin(bintree->node.command))
				execute_non_builtin(bintree->node.command, myenvp, bintree->node.args);//maybe command and args are contained in every node of the bintree?
			else
				execute_builtin(bintree->node.command);
		}
		i++;
	}
	while (i >= 0)
	{
		free(pipe_fd[i]);
		i--;
	}
	free(fd);
	return ;
}