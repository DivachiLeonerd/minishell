/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:24:15 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/05/19 18:36:58 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tree	*node_creator(int id)
{
	t_tree	*node;

	node = malloc(sizeof(t_tree));
	if (!node)
		return (NULL);
	node->tokentype = id;
	node->back = NULL;
	node->left_branch = NULL;
	node->right_branch = NULL;
	return (node);
}

void	create_top_node(t_tree **tree, t_tree *node)
{
	t_tree	*top;

	top = *tree;
	if (!top)
		top = node;
	else
	{
		node->left_branch = top;
		top->back = node;
		top = node;
	}
	*tree = top;
}

void	create_left_node(t_tree *previous, t_tree *new_node)
{
	if (!previous || !new_node)
		return ;
	if (previous->left_branch)
	{
		new_node->left_branch = previous->left_branch;
		previous->left_branch->back = new_node;
	}
	previous->left_branch = new_node;
	new_node->back = previous;
}

void	create_right_node(t_tree *previous, t_tree *node)
{
	if (!previous || !node)
		return ;
	if (previous->right_branch)
	{
		node->left_branch = previous->right_branch;
		previous->right_branch->back = node;
	}
	previous->right_branch = node;
	node->back = previous;
}

t_tree	*find_topof_tree(t_tree *bintree)
{
	t_tree	*node;

	node = bintree;
	if (!bintree)
		return (NULL);
	while (node->back)
	{
		// perror("go back");
		node = node->back;
	}
	return (node);
}
