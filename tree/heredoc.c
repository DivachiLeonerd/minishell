/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:59:26 by afonso            #+#    #+#             */
/*   Updated: 2023/05/15 16:43:20 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../define.h"
#include <stdint.h>

//Function to initialize pipes through the structs
//maybe while doing the tree with heredoc nodes
t_heredoc	*make_heredoc(void)
{
	t_heredoc	*new_heredoc;

	new_heredoc = (t_heredoc *)malloc(sizeof(t_heredoc));
	if (new_heredoc == NULL)
	{
		perror("Couldn't allocate heredoc");
		return (NULL);
	}
	new_heredoc->delimiter = NULL;
	pipe(new_heredoc->pipe_fd);
	return (new_heredoc);
}

ssize_t	get_heredoc_input(t_heredoc *new_heredoc, char *delimiter)
{
	char	buf[200];
	int		i;
	ssize_t	size_read;
	int		ret;

	new_heredoc->delimiter = delimiter;
	printf("delimiter:%s\n", delimiter);
	i = 0;
	while (i < 200)
		buf[i++] = 0;
	ret = 0;
	size_read = 0;
	while (1)
	{
		i = 0;
		write(1, ">", 1);
		size_read = read(0, buf, 200);
		if (ft_strncmp(buf, new_heredoc->delimiter, size_read - 1) == 0)
			break ;
		write(new_heredoc->pipe_fd[1], buf, size_read);
		while (buf[i] && i < 200)
			buf[i++] = 0;
		ret += size_read;
	}
	close (new_heredoc->pipe_fd[1]);
	return ((ssize_t)ret);
}

// close pipes
void	close_heredocs(t_tree *bintree)
{
	t_tree	*node;
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
		if (node->heredoc != NULL)
		{
			close((bintree->heredoc->pipe_fd)[1]);
			close((bintree->heredoc->pipe_fd)[0]);
		}
	}
	//Maybe i also free them along with pipe closure
	return ;
}

void	heredoc_handler(t_heredoc *heredoc)
{
	dup2(heredoc->pipe_fd[0], STDIN_FILENO);
	close(heredoc->pipe_fd[0]);
}