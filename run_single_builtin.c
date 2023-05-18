/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_single_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:14:40 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/18 17:50:03 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	run_single_builtin(t_tree *bintree)
{
	int 	pid;
	char	*name;

	name = find_command_path(bintree->args[0]);
	if (name && !is_builtin(bintree->args[0]))
	{
		free(name);
		pid = fork();
		if (pid == 0)
		{
			
			redirections_handler(bintree);
			execute_non_builtin(bintree->args[0], bintree->args);
			return (0);
		}
		else
			waitpid(pid, NULL, 0);
    }
	if (is_builtin(bintree->args[0]))
	{
		free(name);
		redirections_handler(bintree);
		return (execute_builtin(bintree->args[0], bintree->args)); 
	}
	return (0);
}