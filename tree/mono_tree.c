/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mono_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:32:04 by atereso-          #+#    #+#             */
/*   Updated: 2023/04/24 16:01:21 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//create a node

t_tree *create_node(int tokentype)
{
	static int last_node;
	t_tree		*node;

	if (tokentype == -1)
		return (NULL);
	node = malloc(sizeof(t_tree));
	node->tokentype = tokentype;
	return (node);
}
	node->tokentype = tokentype;
	return (node);
}

void	mono_add_back(t_list **lst, t_list *new)
{
	t_list	*last_position;

	if (lst)
	{
		if (*lst)
		{
			last_position = ft_lstlast(*lst);
			last_position->next = new;
		}
		else
			*lst = new;
		new->next = NULL;
	}
	return ;
}


//join node to back of list 
void	mono_add_back(t_tree **head)
{
    t_tree	*node;

	node = *head;
	//function goes to end of list
}
//done!
    
}
//done!