/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_building_cond.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:48:59 by afonso            #+#    #+#             */
/*   Updated: 2023/02/10 10:05:48 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//PIPES
t_tree	*pipes_cond(int tokentype, t_tree *aux, t_tree *node)
{
	if (aux->tokentype == PIPE && tokentype == COMMAND)
			aux->right_branch == node;
		if (tokentype == PIPE)
			aux->back = node;
	return (node);
}
//REDIRECTS
t_tree	*redir_cond(int tokentype, t_tree *aux, t_tree *node)
{
	if (aux->tokentype == REDIR && tokentype != REDIR)
		{
			while (aux->tokentype != COMMAND)
				aux = aux->back;
			if (aux->back != NULL && aux->back->tokentype == PIPE)
				aux = aux->back;
			return (aux);
		}
	else if (tokentype == REDIR)
			aux->right_branch = node;
	return (node);
}
//COMMANDS

//HEREDOC

//ETC...
