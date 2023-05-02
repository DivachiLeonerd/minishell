/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:04:42 by afonso            #+#    #+#             */
/*   Updated: 2023/05/02 23:43:52 by atereso-         ###   ########.fr       */
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
	int		fd;
	int		fd2;

	fd2 = dup(STDOUT_FILENO);
	fd = open("./ola", O_WRONLY | O_CREAT);
	printf("%d\n", fd);
	dup2(fd, STDOUT_FILENO);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		dup2(fd2, STDOUT_FILENO);
		printf("fd2:%d\n", fd2);
		printf("I'm in child\n");
		close(fd);
		close(STDOUT_FILENO);
		close(fd2);
		return (0);
	}
	else
	{
		waitpid(pid,NULL,0);
		printf("IM PARENT\n");
		close(STDOUT_FILENO);
		close(fd);
		close(fd2);
	}
	return (0);
}
