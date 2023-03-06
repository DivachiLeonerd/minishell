/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:08:01 by afonso            #+#    #+#             */
/*   Updated: 2023/03/06 15:30:07 by afonso           ###   ########.fr       */
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
	char	buf[INT32_MAX];
	t_heredoc *heredoc;
	ssize_t		size_read;
	
	// i = 0;
	// bintree = build_tree(argv, envp);
	heredoc = make_heredoc();
	get_heredoc_input(heredoc);
	size_read = read((heredoc->pipe_fd)[0], buf, INT32_MAX);
	printf("size_read:%lld\n%s\n",size_read, buf);
	//make a tree with parsing
	//run tree with make_and_run_pipes()
	return (0);
}