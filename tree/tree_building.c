/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_building.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:27:54 by afonso            #+#    #+#             */
/*   Updated: 2023/02/10 09:30:44 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"



t_tree	*add_to_tree(int tokentype)
{
	//this function should be called repeatedly with a different token and tokentype
	//I should add nodes with the tokentype and connect the nodes
	//this is coming from the end of the tree to the beggining
	t_tree	*node;
	static t_tree *aux;

	node = malloc(sizeof(t_tree));
	node->tokentype = tokentype;
	if (aux->tokentype == REDIR && tokentype != REDIR)
	{
		while (aux->tokentype != COMMAND)
			aux = aux->back;
		if (aux->back != NULL && aux->back->tokentype == PIPE)
			aux = aux->back;
		return (aux);
	}
	if (aux->tokentype == PIPE && tokentype == COMMAND)
		aux->right_branch == node;
	if (tokentype == PIPE)
		aux->back = node;
	else if (tokentype == REDIR)
		aux->right_branch = node;
	
	return (aux = node);
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