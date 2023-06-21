/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_building_cond.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:48:59 by afonso            #+#    #+#             */
/*   Updated: 2023/06/02 18:20:45 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tree	*pipes_cond(int tokentype, t_tree *last_node, t_tree *node)
{
	if (last_node->tokentype == PIPE && (node->tokentype == BUILTIN
			|| node->tokentype == EXECUTABLE))
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

t_tree	*redir_cond(t_tree *last_node, t_tree *node)
{
	if (!(node->tokentype == I_REDIR || node->tokentype == O_REDIR
			|| node->tokentype == APPEND
			|| node->tokentype == HEREDOC) && (last_node->tokentype == I_REDIR
			|| last_node->tokentype == O_REDIR
			|| last_node->tokentype == APPEND
			|| last_node->tokentype == HEREDOC))
	{
		while (!(last_node->tokentype == I_REDIR
				|| last_node->tokentype == O_REDIR)
			|| last_node->tokentype == APPEND
			|| last_node->tokentype == HEREDOC)
			last_node = last_node->back;
		if (last_node->back != NULL && last_node->back->tokentype == PIPE)
			last_node = last_node->back;
		return (last_node);
	}
	else if ((node->tokentype == I_REDIR || node->tokentype == O_REDIR
			|| node->tokentype == APPEND
			|| node->tokentype == HEREDOC) || node->tokentype == HEREDOC)
	{
		last_node->right_branch = node;
		node->back = last_node;
	}
	return (node);
}
