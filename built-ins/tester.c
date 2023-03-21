/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:04:42 by afonso            #+#    #+#             */
/*   Updated: 2023/03/06 15:29:04 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "built-ins.h"
#include "piping.h"
#include "define.h"
#include "libft.h"

static void	free_utils(int *pid, int **pipe_fd, int numof_pipes)
{
	int	i;
	
	i = numof_pipes;
	while (i >= 0)
	{
		free(pipe_fd[i]);
		i--;
	}
	free(pid);
	return ;
}

void	run_pipes(int numof_pipes, t_tree *bintree, int *pid, char **myenvp)
{
	int	i;
	t_tree *node;

	i = 0;
	while (i <= numof_pipes)
	{
		if (pid[i] == 0)
		{
			node = find_command_node(i, bintree);//command index is the position of each command in command line
			if (return_righttokenid(node) == O_REDIR)//NO FUTURO, vou transformar todos os redirects numa execute_built-in()
				output_redirection(STDOUT_FILENO, node);
			if (is_builtin((node->args)[0]))
				execute_builtin((node->args)[0], myenvp, node->args);
			else
				execute_non_builtin((node->args)[0], myenvp, node->args);
		}
		i++;
	}
}

void	make_pipes(t_tree *bintree, char **myenvp)
{
	int		i;
	int		numof_pipes;
	int		**pipe_fd;
	int		*pid;
	int		**heredoc_fd;
	int		numof_heredocs;
	
	i = 0;
	numof_pipes = how_many_pipes(bintree);
	pid = malloc((numof_pipes + 1) * sizeof(int));//if there is 3 processes then we will need only 2 pipes
	pipe_fd = pipe_creation(numof_pipes);
	initialize_forking_processes(pid, numof_pipes + 1);
	while (i <= numof_pipes)
		piping(pid, pipe_fd, numof_pipes, i++);
	run_pipes(numof_pipes, bintree, pid, myenvp);
	free_utils(pid, pipe_fd, numof_pipes);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	int	**pipe_fd;
	int *pid;
	int i;
	char	buf[INT32_MAX];
	t_tree	*bintree;
	t_heredoc *heredoc;
	ssize_t		size_read;
	
	// i = 0;
	// bintree = build_tree(argv, envp);
	heredoc = make_heredoc();
	get_heredoc_input(heredoc);
	size_read = read((heredoc->pipe_fd)[0], buf, INT32_MAX);
	printf("%s", buf);
	//make a tree with parsing
	//run tree with make_and_run_pipes()
	return (0);
}
