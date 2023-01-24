/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:48:03 by afonso            #+#    #+#             */
/*   Updated: 2023/01/24 11:50:22 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_redirection(t_tree *command_node)
{
	if (command_node->rightbranch == NULL)
		return (0);
	else
		return (command_node->rightbranch->tokenid);
}