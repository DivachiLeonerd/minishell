/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:04:42 by afonso            #+#    #+#             */
/*   Updated: 2023/01/28 11:00:55 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

// void	free_utils(int *pid, int **pipe_fd, int numof_pipes)
// {
// 	int	i;
	
// 	i = numof_pipes;
// 	while (i >= 0)
// 	{
// 		free(pipe_fd[i]);
// 		i--;
// 	}
// 	free(pid);
// 	return ;
// }

int	main(int argc, char **argv, char **envp)
{
	int	**pipe_fd;
	int *pid;
	int i;

	i = 0;
	ft_echo(argv, envp);
	//gotta test make_and_run_pipes

	return (0);
}

// void	make_and_run_pipes(t_tree *bintree, char **myenvp)
// {
// 	int		i;
// 	int		numof_pipes;
// 	int		**pipe_fd;
// 	int		*pid;
// 	t_tree	*node;
	
// 	node = find_first_command(bintree); //function returns first command typed in the command line
// 	i = 0;
// 	numof_pipes = how_many_pipes(bintree);
// 	pid = malloc((numof_pipes + 1) * sizeof(int));//if there is 3 processes then we will need only 2 pipes
// 	pipe_fd = pipe_creation(numof_pipes);
// 	initialize_forking_processes(pid, numof_pipes + 1);
// 	while (i <= numof_pipes)
// 		piping(pid, pipe_fd, numof_pipes, i++);
// 	i = 0;
// 	while (i <= numof_pipes)
// 	{
// 		if (pid[i] == 0)
// 		{
// 			if (return_tokenid(node) == REDIR)//vou transformar todos os redirects numa execute_built-in()
// 				output_redirection(STDOUT_FILENO, node);
// 			if (is_builtin(node))
// 				execute_builtin((node->args)[0], myenvp, node->args);
// 			else
// 				execute_non_builtin((node->args)[0], myenvp, node->args);
// 		}
// 		i++;
// 	}
// 	free_utils(pid, pipe_fd, numof_pipes);
// }
