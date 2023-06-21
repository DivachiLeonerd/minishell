/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_building.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:27:54 by afonso            #+#    #+#             */
/*   Updated: 2023/06/02 18:16:47 by atereso-         ###   ########.fr       */
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
