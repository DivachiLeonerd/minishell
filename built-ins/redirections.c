/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:48:03 by afonso            #+#    #+#             */
/*   Updated: 2023/05/08 18:53:33 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piping.h"

int	return_righttokenid(t_tree *command_node)
{
	if (!command_node)
		return (-1);
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

int	output_redirection(int fd, t_tree *node, int token_type)
{
	if (token_type == O_REDIR)
		fd = open(node->args[0] /*filename*/, O_CREAT | O_WRONLY);
	else if (token_type == O_APPEND)
		fd = open(node->args[0], O_CREAT  | O_WRONLY | O_APPEND);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	input_redirection(int fd, t_tree *node, int token_type)
{
	if (token_type == I_REDIR)
		fd = open(node->args[0] /*filename*/, O_CREAT | O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}