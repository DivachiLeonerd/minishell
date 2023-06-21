/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:59:26 by afonso            #+#    #+#             */
/*   Updated: 2023/06/02 18:16:22 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

static void	free_node(t_tree *node)
{
	if (node->heredoc)
		free(node->heredoc->pipe_fd);
	if (node->args)
		free_matrix(node->args);
	free(node);
	return ;
}

void	free_aux(t_tree **node, int side, t_tree *aux)
{
	aux = *node;
	if (side == LEFT)
		*node = (*node)->left_branch;
	else
		*node = (*node)->back;
	free_node(aux);
	if (side == LEFT)
		(*node)->back = NULL;
	else
		(*node)->right_branch = NULL;
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
	aux = NULL;
	while (1)
	{
		temp = node;
		while (check_direction(RIGHT, node) == 0)
			node = node->right_branch;
		while (node != temp)
			free_aux(&node, 0, aux);
		if (check_direction(LEFT, node) == 0)
			free_aux(&node, LEFT, aux);
		else
			return (free_node(node));
	}
	return ;
}
