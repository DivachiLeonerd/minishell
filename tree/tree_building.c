/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_building.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:27:54 by afonso            #+#    #+#             */
/*   Updated: 2023/02/28 11:38:40 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"



t_tree	*add_to_tree(int tokentype, char **args)
{
	//this function should be called repeatedly with a different token and tokentype
	//I should add nodes with the tokentype and connect the nodes
	//this is coming from the end of the tree to the beggining
	t_tree	*node;
	static t_tree *aux;

	node = malloc(sizeof(t_tree));
	node->tokentype = tokentype;
	node->args = args;
	node = redir_cond(tokentype, aux, node);
	node = pipes_cond(tokentype, aux, node);
	//etc
	aux = node;
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

t_tree	*build_tree(char *command_line, char **envp)
{
	t_tree	*head;
	t_tree	*node;

	parser_init(command_line, envp);
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