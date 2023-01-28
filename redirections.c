/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:48:03 by afonso            #+#    #+#             */
/*   Updated: 2023/01/27 19:50:27 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	return_righttokenid(t_tree *command_node)
{
	if (command_node->rightbranch == NULL)
		return (0);
	else
		return (command_node->rightbranch->tokenid);
}

t_tree	*find_first_command(t_tree *bintree)
{
	t_tree	*node;

	node = bintree;
	while (node->leftbranch != NULL)
		node = node->leftbranch;
	return (node);
}