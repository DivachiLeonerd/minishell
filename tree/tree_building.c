/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_building.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:27:54 by afonso            #+#    #+#             */
/*   Updated: 2023/02/06 17:20:41 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tree	*build_tree(char *token, int tokentype)
{
	t_tree	*head;
	t_tree	*node;

	
}

int	check_direction(int direction, t_tree *node)
{
	
	if (direction == 1)//left side
	{
		if (node->left_branch != NULL)
			return (0);
	}
	if (direction == 2)//right side
	{
		if (node->right_branch != NULL)
			return (0);
	}
	return (1);
}

void	free_tree(t_tree *bintree)
{
	t_tree	*node;
	t_tree	*temp;

	node = find_command_node(0, bintree);
	while (node != bintree)
	{
		if (check_direction(LEFT, node) == 0)
			node = node->left_branch;
		else if (check_direction(RIGHT, node) == 0)
			node = node->right_branch;
		else
		{
			temp = node->back;
			if (temp->left_branch == node)
				temp->left_branch == NULL;
			else if (temp->right_branch == NULL)
				temp->right_branch == NULL;
			free(node);
		}
		node = temp;
	}
	return ;
}