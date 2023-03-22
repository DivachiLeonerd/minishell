/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:48:03 by afonso            #+#    #+#             */
/*   Updated: 2023/03/21 17:57:35 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piping.h"

int	return_righttokenid(t_tree *command_node)
{
	if (command_node->right_branch == NULL)
		return (0);
	else
		return (command_node->right_branch->tokentype);
}

t_tree	*find_first_command(t_tree *bintree)
{
	t_tree	*node;

	node = bintree;
	while (node->left_branch != NULL)
		node = node->left_branch;
	return (node);
}