/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:59:26 by afonso            #+#    #+#             */
/*   Updated: 2023/03/18 16:43:10 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../define.h"
#include <stdint.h>

//Function to initialize pipes through the structs
//maybe while doing the tree with heredoc nodes
t_heredoc *make_heredoc(void)
{
	t_heredoc	*new_heredoc;
	
	new_heredoc = malloc (sizeof(t_heredoc));
	if (new_heredoc == NULL)
	{
		perror("Couldn't allocate heredoc");
		return (NULL);
	}
	pipe(new_heredoc->pipe_fd);
	return (new_heredoc);
}

ssize_t	get_heredoc_input(t_tree *node, char *delimiter)
{
	char	buf[200];
	int		i;
	int		size_read;
	int		ret;

	node->args[0] = delimiter;
	i = 0;
	while (i < 200)
		buf[i++] = 0;
	i = 0;
	ret = 0;
	size_read = 0;
	while (1)
	{
		size_read = read(0, buf, 200);
		if (ft_strncmp(&(buf[0]), node->args[0],
				ft_strlen(buf) - 1) == 0)
			break ;
		write(node->heredoc->pipe_fd[1], buf, size_read);
		while (buf[i] && i < 200)
			buf[i++] = 0;
		ret += size_read;
		i = 0;
	}
	return ((ssize_t)ret);
}

// close pipes
void	close_heredocs(t_tree *bintree)
{
	t_tree *node;
	t_tree	*right;
	
	node = bintree;
	right = node->right_branch;
	while (node->left_branch != NULL)
	{
		while (right != NULL)
		{
			if (right->heredoc != NULL)
			{
				close((bintree->heredoc->pipe_fd)[1]);
				close((bintree->heredoc->pipe_fd)[0]);
			}
			right = right->right_branch;
		}
		if (node->heredoc !=NULL)
		{
			close((bintree->heredoc->pipe_fd)[1]);
			close((bintree->heredoc->pipe_fd)[0]);
		}
	}
	//Maybe i also free them along with pipe closure
	return ;
}