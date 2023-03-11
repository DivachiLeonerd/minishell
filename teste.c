/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:08:01 by afonso            #+#    #+#             */
/*   Updated: 2023/03/09 13:23:03 by afonso           ###   ########.fr       */
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
	heredoc = make_heredoc();
	// printf("ola\n");
	heredoc->delimiter = "Marianna";
	size_read = get_heredoc_input(heredoc);
	// printf("ola\n");
	read((heredoc->pipe_fd)[0], buf, size_read);
	printf("size_read:%ld\n", size_read);
	while (size_read >= i)
		printf("%c", buf[i++]);
	close(heredoc->pipe_fd[0]);
	close(heredoc->pipe_fd[1]);
	free(heredoc);
	//make a tree with parsing
	//run tree with make_and_run_pipes()
	return (0);
}