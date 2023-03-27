/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_building_cond.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:48:59 by afonso            #+#    #+#             */
/*   Updated: 2023/03/22 19:08:56 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//PIPES
t_tree	*pipes_cond(int tokentype, t_tree *last_node, t_tree *node)
{
	if (last_node->tokentype == PIPE && COMMAND)
	{
		last_node->right_branch = node;
		node->back = last_node;
	}
	if (tokentype == PIPE)
		last_node->back = node;
	return (node);
}
//REDIRECTS
t_tree	*redir_cond(t_tree *last_node, t_tree *node)
{
	//if tokentype != REDIR but last token == REDIR
	if (!REDIR && (last_node->tokentype == I_REDIR || last_node->tokentype == O_REDIR))
	{
		//go back in the tree until last_node == COMMAND
		while (!(last_node->tokentype == 5 || last_node->tokentype == 6))
			last_node = last_node->back;
		//if there's a pipe behind the command, go back
		if (last_node->back != NULL && last_node->back->tokentype == PIPE)
			last_node = last_node->back;
		//return last_node in the pipe or command position
		return (last_node);
	}
	//or tokentype is redir
	else if (REDIR)
	{
		last_node->right_branch = node;
		node->back = last_node;
	}
	//return it in the last redir position
	return (node);
}

//ETC...
