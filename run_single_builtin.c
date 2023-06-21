/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_single_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:14:40 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/23 16:58:59 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	run_single_builtin(t_tree *bintree)
{
	int		pid;
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
		g_struct.behaviour.sa_handler = SIG_IGN;
		sigaction(SIGINT, &(g_struct.behaviour), NULL);
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
