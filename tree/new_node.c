/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:19:25 by afonso            #+#    #+#             */
/*   Updated: 2023/01/16 21:44:17 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void create_redir_node(t_tree **tree, t_tree *node)
{
	t_tree *top;
	t_tree *bottom;

	if (!tree)
		return ;
	top = *tree;
	if (!top)
		create_top_node(node, tree);
	elif (node_is_redir(top) || node_is_command(top))
		create_left_node(node, top);
	elif (node_is_pipe(top))
	{
		bottom = top->right;
		if (!bottom || node_is_redir(bottom))
			create_right_node(node, top);
		else
			create_left_node(node, bottom);
	}
}

static void create_command_node(t_tree **tree, t_tree *node)
{
	t_tree *top;
	
	top = *tree;
	if (node_is_redir(top) || !top)
		create_top_node(node, tree);
	elif (node_is_pipe(top))
		create_right_node(node, tree);
}

static void create_pipe_node(t_tree **tree, t_tree *node)
{
	create_top_node(node, tree);
}

void	create_node(t_tree **tree, t_tree *node)
{
	if (node_is_redir(node))
		create_redir_node(node, tree);
	elif (node_is_command(node))
		create_command_node(node, tree);
	elif (node_is_pipe(node))
		create_pipe_node(node, tree);
	
}
