/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mono_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:32:04 by atereso-          #+#    #+#             */
/*   Updated: 2023/04/24 19:43:09 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//create a node

t_tree *mono_create_node(int tokentype)
{
	static int last_node;
	t_tree		*node;

	if (tokentype == -1)
		return (NULL);
	node = malloc(sizeof(t_tree));
	node->tokentype = tokentype;
	return (node);
}

t_tree	*mono_last(t_tree *head)
{
	t_tree	*pointer;

	if (!head)
		return (NULL);
	pointer = head;
	while (pointer->next)
		pointer = pointer->next;
	return (pointer);
}

//join node to back of list 
void	mono_add_back(t_tree **head, t_tree *new)
{
	t_tree	*last_position;

	if (head)
	{
		if (*head)
		{
			last_position = mono_last(head);
			last_position->next = new;
		}
		else
			*head = new;
		new->next = NULL;
	}
	return ;
}

t_tree	*add_to_tree(int tokentype, t_tree *last_node)
{
	mono_add_back(&last_node, mono_create_node(tokentype));
	return (mono_last(last_node));
}
//done!