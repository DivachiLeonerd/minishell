/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_building_cond.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:48:59 by afonso            #+#    #+#             */
/*   Updated: 2023/05/16 16:08:09 by atereso-         ###   ########.fr       */
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
	{
		if (last_node->back && last_node->back->tokentype == PIPE)
		{
			last_node->back->back = node;
			last_node->back->back->left_branch = last_node->back;
		}
		else
		{
			last_node->back = node;
			node->left_branch = last_node;
		}
	}
	return (node);
}

//REDIRECTS
t_tree	*redir_cond(t_tree *last_node, t_tree *node)
{
	//if tokentype != REDIR but last token == REDIR
	if (!REDIR && (last_node->tokentype == I_REDIR
			|| last_node->tokentype == O_REDIR
			|| last_node->tokentype == APPEND
			|| last_node->tokentype == HEREDOC))
	{
		//go back in the tree until last_node == COMMAND
		while (!(last_node->tokentype == I_REDIR
				|| last_node->tokentype == O_REDIR)
				|| last_node->tokentype == APPEND
				|| last_node->tokentype == HEREDOC)
			last_node = last_node->back;
		//if there's a pipe behind the command, go back
		if (last_node->back != NULL && last_node->back->tokentype == PIPE)
			last_node = last_node->back;
		//return last_node in the pipe or command position
		return (last_node);
	}
	//or tokentype is redir
	else if (REDIR || node->tokentype == HEREDOC)
	{
		last_node->right_branch = node;
		node->back = last_node;
	}
	//return it in the last redir position
	return (node);
}

//ETC...
