/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:04:42 by afonso            #+#    #+#             */
/*   Updated: 2023/01/23 17:32:55 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

void	free_utils(int *pid, int **pipe_fd, int numof_pipes)
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

int	main(int argc, char **argv, char **envp)
{
	int	**pipe_fd;
	int *pid;
	int i;

	i = 0;
	//gotta test make_and_run_pipes

	return (0);
}

//Needs to be shortened by dividing into smaller functions
//Should be tested first though
void	make_and_run_pipes(t_tree *bintree, char **myenvp)
{
	int		i;
	int		numof_pipes;
	int		**pipe_fd;
	int		*pid;
	t_tree	*node;
	
	node = find_first_command(bintree); //function returns first command typed in the command line
	i = 0;
	numof_pipes = how_many_pipes(bintree);
	pid = malloc((numof_pipes + 1) * sizeof(int));
	pipe_fd = pipe_creation(numof_pipes);
	initialize_forking_processes(pid, numof_pipes + 1);
	while (i <= numof_pipes)
	{
		piping(pid, pipe_fd, numof_pipes, i);
		i++;
	}
	i = 0;
	while (i <= numof_pipes)
	{
		if (pid[i] == 0)
		{
			if (has_redirection(node) == 1)
				output_redirection(STDOUT_FILENO, node);//bintree has to be substituted for another t_tree*node
			if (is_builtin(node))
				execute_builtin((node->args)[0], myenvp, node->args);
			else
				execute_non_builtin((node->args)[0], myenvp, node->args);
		}
		i++;
	}
	free_utils(pid, pipe_fd, numof_pipes);
}
