/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_building.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:27:54 by afonso            #+#    #+#             */
/*   Updated: 2023/05/23 16:23:59 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../built-ins/piping.h"
#include "../define.h"
#include "minishell.h"

void	i_dont_know_dude(int tokentype, t_tree *node)
{
	(void)node;
	if (tokentype == WORD)
	{
		g_struct.chad_exitstatus = 2;
		node = NULL;
		return ;
	}
}

/*this function should be called repeatedly with a different token and tokentype
I should add nodes with the tokentype and connect the nodes
this is coming from the end of the tree to the beggining*/
t_tree	*add_to_tree(int tokentype, t_tree *last_node)
{
	t_tree			*node;

	if (tokentype == -1)
		return (last_node);
	node = malloc(sizeof(t_tree));
	node->back = NULL;
	node->tokentype = tokentype;
	node->args = NULL;
	node->left_branch = NULL;
	node->right_branch = NULL;
	node->heredoc = NULL;
	if (last_node)
	{
		node = redir_cond(last_node, node);
		node = pipes_cond(tokentype, last_node, node);
	}
	else
		i_dont_know_dude(tokentype, node);
	return (node);
}

int	check_direction(int direction, t_tree *node)
{
	if (direction == LEFT)
	{
		if (node->left_branch != NULL)
			return (0);
	}
	if (direction == RIGHT)
	{
		if (node->right_branch != NULL)
			return (0);
	}
	return (1);
}

static void	free_node(t_tree *node)
{
	if (node->heredoc)
		free(node->heredoc->pipe_fd);
	if (node->args)
		free_matrix(node->args);
	free(node);
	return ;
}

void	free_tree(t_tree *bintree)
{
	t_tree	*node;
	t_tree	*temp;
	t_tree	*aux;

	if (!bintree)
		return ;
	while (bintree->back != NULL)
		bintree = bintree->back;
	node = bintree;
	while (1)
	{
		temp = node;
		while (check_direction(RIGHT, node) == 0)
			node = node->right_branch;
		while (node != temp)
		{
			aux = node;
			node = node->back;
			free_node(aux);
			node->right_branch = NULL;
		}
		if (check_direction(LEFT, node) == 0)
		{
			aux = node;
			node = node->left_branch;
			free_node(aux);
			node->back = NULL;
		}
		else
			return (free_node(node));
	}
	return ;
}
