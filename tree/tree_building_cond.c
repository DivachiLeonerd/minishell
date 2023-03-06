/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_building_cond.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:48:59 by afonso            #+#    #+#             */
/*   Updated: 2023/03/06 15:12:00 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//PIPES
t_tree	*pipes_cond(int tokentype, t_tree *aux, t_tree *node)
{
	if (aux->tokentype == PIPE && COMMAND)
			aux->right_branch = node;
	if (tokentype == PIPE)
		aux->back = node;
	return (node);
}
//REDIRECTS
t_tree	*redir_cond(t_tree *aux, t_tree *node)
{
	//if tokentype != REDIR but last token == REDIR
	if (!REDIR && (aux->tokentype == 0 || aux->tokentype == 1))
	{
		//go back in the tree until aux == COMMAND
		while (!(aux->tokentype == 5 || aux->tokentype == 6))
			aux = aux->back;
		//if there's a pipe behind the command, go back
		if (aux->back != NULL && aux->back->tokentype == PIPE)
			aux = aux->back;
		//return aux in the pipe or command position
		return (aux);
	}
	//or tokentype is redir
	else if (REDIR)
			aux->right_branch = node;
	//return it in the last redir position
	return (node);
}
//COMMANDS

//HEREDOC
t_tree	*heredoc_cond(int tokentype, t_tree *aux, t_tree *node)
{
	if (tokentype == HEREDOC)
	{
		node->heredoc = make_heredoc();
		get_heredoc_input(node->heredoc);
	}
	else
		node->heredoc = NULL;
	aux->back = node;
	return (node);
}
//ETC...
