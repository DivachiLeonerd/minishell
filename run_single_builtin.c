/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_single_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:14:40 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/09 19:10:08 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

char	**run_single_builtin(t_tree *bintree, char **myenvp)
{
	int 	pid;
	char	*name;

	name = find_command_path(myenvp, bintree->args[0]);
	if (name && !is_builtin(bintree->args[0]))
	{
		free(name);
		pid = fork();
		if (pid == 0)
		{
			execute_non_builtin(bintree->args[0], myenvp, bintree->args);
			return (myenvp);
		}
		else
			waitpid(pid, NULL, 0);
    }
	if (is_builtin(bintree->args[0]))
	{
		free(name);
		printf("executing single built in\n");
		return (execute_builtin(bintree->args[0], myenvp, bintree->args));
	}
	return (myenvp);
}