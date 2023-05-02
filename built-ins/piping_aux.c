/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:47:06 by afonso            #+#    #+#             */
/*   Updated: 2023/05/02 22:30:55 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	how_many_pipes(t_tree *bintree)
{
	int		numof_pipes;
	t_tree	*node;

	numof_pipes = 0;
	node = bintree;
	while (node->left_branch != NULL)
	{
		if (node->tokentype == PIPE)
			numof_pipes++;
		node = node->left_branch;
	}
	return (numof_pipes);
}

void	run_processes(t_tree *node, char **myenvp)
{
	redirections_handler();
	heredoc_handler();
	if (node->tokentype == BUILTIN)
		exit(execute_builtin((node->args)[0], myenvp , node->args));
	else if (node->tokentype == EXECUTABLE)
		exit(execute_non_builtin((node->args)[0], myenvp, node->args));
	return ;
}

char	**make_processes(t_tree *bintree, char **myenvp, int command_num)
{
	int		numof_pipes;
	int		pid;
	t_tree	*node;

	numof_pipes = how_many_pipes(bintree);
	//check if the one command is a builtin and if it is, just run it
	if (check_one_command_line(bintree))
	{
		run_single_builtin();
		return ;
	}
	multiple_processes(command_num, bintree);
	// go through tree, if there's a pipe "behind" our command we pipe, dup and close useless
	
	//get everything until a pipe, including redirs

	//pipe if there is one [pipe] and close everything useless
	return (myenvp);
}
