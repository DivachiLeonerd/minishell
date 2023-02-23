/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:59:26 by afonso            #+#    #+#             */
/*   Updated: 2023/02/23 17:04:28 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Function to initialize pipes through the structs
//maybe while doing the tree with heredoc nodes
t_heredoc *make_heredoc(int fd_in)
{
	static int	index;
	t_heredoc	*new_heredoc;
	char 		*buf;
	ssize_t		bytes_read;
	
	new_heredoc = malloc (sizeof(t_heredoc));
	if (new_heredoc == NULL)
	{
		perror("Couldn't allocate heredoc");
		return (NULL);
	}
	new_heredoc->index = index;
	pipe(new_heredoc->pipe_fd);
	bytes_read = read(0, buf, 50);
	writeto_heredoc(new_heredoc, bytes_read);
	index++;
	return (new_heredoc);
}

char	*writeto_heredoc(t_heredoc *heredoc, ssize_t bytes_read)
{
	char		*buf;
	//first I gotta check what im writing ends in the delimiter
	//anything after the delimiter has no business being written
	write((heredoc->pipe_fd)[0], buf, ft_strlen(buf));
}
//close pipes

void	close_heredocs(t_heredoc **all_heredocs)
{
	t_heredoc	*hd;
	
	hd = *all_heredocs;
	while (hd)
	{
		close((hd->pipe_fd)[0]);
		close((hd->pipe_fd)[1]);
		hd++;//I'm thinking it will go up (sizeof(t_heredoc)) and not just 1
	}
	return ;
}