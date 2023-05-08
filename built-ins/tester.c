/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:04:42 by afonso            #+#    #+#             */
/*   Updated: 2023/05/05 18:55:45 by atereso-         ###   ########.fr       */
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
	int		pipe_fd[2];
	char	*buf;

	pipe(pipe_fd);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("IM PARENT\n");
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		printf("message to parent\n");
		close(STDOUT_FILENO);
		close(pipe_fd[0]);
	}
	else
	{
		waitpid(pid, NULL, 0);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		printf("I'm in child\n");
		buf = readline("NULL: ");
		printf("%s\n", buf);
		free(buf);
		close(STDIN_FILENO);
		close(pipe_fd[1]);
	}
	return (0);
}
