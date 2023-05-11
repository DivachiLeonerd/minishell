/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:04:42 by afonso            #+#    #+#             */
/*   Updated: 2023/05/11 12:12:09 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "built-ins.h"
#include "piping.h"
#include "../define.h"
#include "../libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	char	**myenvp;
	int		pid;
	int		**pipe_fd;
	char	*buf;
	int		x = 2;

	pipe_fd = malloc(2 * sizeof(int *));
	pipe_fd[0] = malloc(2 * sizeof(int));
	pipe_fd[1] = malloc(2 * sizeof(int));
	pipe(pipe_fd[0]);
	pipe(pipe_fd[1]);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("Im child\n");
		printf("In process child:\npipe_fd[1][1]:%d\npipe_fd[1[0]:%d\npipe_fd[0][0]:%d\npipe_fd[0][1]:%d\n", pipe_fd[1][1], pipe_fd[1][0], pipe_fd[0][1], pipe_fd[0][0]);
		x = 3;
		printf("pipefd address:%p and &x:%p %d\n", pipe_fd, &x, x);
	}
	else
	{
		wait(NULL);
		printf("IM PARENT\n");
		printf("In process child:\npipe_fd[1][1]:%d\npipe_fd[1[0]:%d\npipe_fd[0][0]:%d\npipe_fd[0][1]:%d\n", pipe_fd[1][1], pipe_fd[1][0], pipe_fd[0][1], pipe_fd[0][0]);
		printf("pipefd address:%p and &x:%p %d\n", pipe_fd, &x, x);

	}
	free(pipe_fd[0]);
	free(pipe_fd[1]);
	free(pipe_fd);
	close(pipe_fd[0][0]);
	close(pipe_fd[0][1]);
	close(pipe_fd[1][0]);
	close(pipe_fd[1][1]);
	return (0);
}
