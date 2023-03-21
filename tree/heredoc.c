/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:59:26 by afonso            #+#    #+#             */
/*   Updated: 2023/03/16 19:42:04 by afonso           ###   ########.fr       */
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
		//what if delimiter is divided between one read and another? gotta fix this
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

//close pipes
// void	close_heredocs(t_heredoc **all_heredocs)
// {
// 	t_heredoc	*hd;
	
// 	hd = *all_heredocs;
// 	while (hd)
// 	{
// 		close((hd->pipe_fd)[0]);
// 		close((hd->pipe_fd)[1]);
// 		hd++;//I'm thinking it will go up (sizeof(t_heredoc)) and not just 1
// 	}
// 	//Maybe i also free them along with pipe closure
// 	return ;
// }