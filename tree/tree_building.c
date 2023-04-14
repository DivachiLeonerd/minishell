/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_building.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:27:54 by afonso            #+#    #+#             */
/*   Updated: 2023/04/14 11:44:12 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../built-ins/piping.h"
#include "../define.h"

t_tree	*add_to_tree(int tokentype, char **args, t_tree *last_node)
{
	//this function should be called repeatedly with a different token and tokentype
	//I should add nodes with the tokentype and connect the nodes
	//this is coming from the end of the tree to the beggining
	t_tree			*node;

	if (tokentype == -1)
	{
		return (last_node);
	}
	node = malloc(sizeof(t_tree));
	node->back = NULL;
	node->tokentype = tokentype;
	node->args = args;
	node->left_branch = NULL;
	node->right_branch = NULL;
	printf("In add_to_tree():adding a node of %d tokentype value\n", node->tokentype);
	if (last_node)
	{
		node = redir_cond(last_node, node);
		node = pipes_cond(tokentype, last_node, node);
	}
	else
	{
		if (tokentype == WORD)
		{
			chad_exitstatus = 10;
			perror("command cannot be found");
			free(node);
			node = NULL;
			return (NULL);
		}
	}
	return (node);
}

int	check_direction(int direction, t_tree *node)
{
	
	if (direction == LEFT)//left side
	{
		if (node->left_branch != NULL)
			return (0);
	}
	if (direction == RIGHT)//right side
	{
		if (node->right_branch != NULL)
			return (0);
	}
	return (1);
}

static void free_node(t_tree *node)
{
	free_matrix(node->args);
	free(node);
	return ;
}

void	free_tree(t_tree *bintree)
{
	t_tree	*node;
	t_tree	*temp;

	if (!bintree)
		return ;
	while (bintree->back != NULL)//tries to find the first position of the tree
		bintree = bintree->back;
	node = bintree;
	while (node->left_branch != NULL)
	{
		if (check_direction(LEFT, node) == 0)
			node = node->left_branch;
		else if (check_direction(RIGHT, node) == 0)
			node = node->right_branch;
		else
		{
			temp = node->back;
			if (check_direction(LEFT, temp) != 0)
				temp->left_branch = NULL;
			else if (temp->right_branch == NULL)
				temp->right_branch = NULL;
			free_node(node);
		}
		node = temp;
	}
	free_node(bintree);
	return ;
}