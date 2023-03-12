/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:08:01 by afonso            #+#    #+#             */
/*   Updated: 2023/03/12 16:34:35 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Ignore this file for now
// int main(void)
// {
// 	char	*line;
// 	int		exit_status;
// 	pid_t 	pid;

// 	pid  = fork();
// 	line = 0;
// 	if (pid == 0)
// 		exit (20);
// 	else
// 	{
// 		waitpid(pid, &errno, WEXITSTATUS(errno));
// 		printf("errno:%d\n", errno >> 8);
// 		return (errno >> 8);
// 	}
// }

int	main(int argc, char **argv, char **envp)
{
	char	buf[1000];
	t_heredoc *heredoc;
	ssize_t		size_read;
	ssize_t		i;
	// int			i;
	i = 0;
	// bintree = build_tree(argv, envp);
	(void)argc;
	(void)argv;
	(void)envp;
	//Isto acontece no inicio da tree
	heredoc = make_heredoc();
	size_read = get_heredoc_input(heredoc, "Sofia");
	//isto é o que o programa tem que fazer para os ler
	read((heredoc->pipe_fd)[0], buf, size_read);
	printf("size_read:%ld\n", size_read);
	while (size_read > i)
		printf("%c", buf[i++]);
	//closing pipe
	close(heredoc->pipe_fd[0]);
	close(heredoc->pipe_fd[1]);
	free(heredoc);
	//make a tree with parsing
	//run tree with make_and_run_pipes()
	return (0);
}