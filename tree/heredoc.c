/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:59:26 by afonso            #+#    #+#             */
/*   Updated: 2023/03/09 13:38:54 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../define.h"
#include <stdint.h>

//Function to initialize pipes through the structs
//maybe while doing the tree with heredoc nodes
t_heredoc *make_heredoc(void)
{
	static int	index;
	t_heredoc	*new_heredoc;
	
	new_heredoc = malloc (sizeof(t_heredoc));
	if (new_heredoc == NULL)
	{
		perror("Couldn't allocate heredoc");
		return (NULL);
	}
	new_heredoc->index = index;
	pipe(new_heredoc->pipe_fd);
	index++;
	return (new_heredoc);
}

ssize_t	get_heredoc_input(t_heredoc *heredoc)
{
	char	buf[1000];
	int		i;
	int		size_read;
	buf[1000 - 1] = 0;
	size_read = 0;
	i = 0;
	while (1)
	{
		//what if delimiter is divided between one read and another? gotta fix this
		//Maybe I just put buf[INT_MAX]
		read(0, buf, 1000);
		while (buf[i] && (ft_strncmp(&(buf[i]), heredoc->delimiter,
				ft_strlen(heredoc->delimiter)) != 0))
		{
			// printf("delimiter not found && %s\n", heredoc->delimiter);			
			i++;
		}
		buf[i] = 0;
		
		write(heredoc->pipe_fd[1], buf, i);
		size_read += i;
		if (ft_strncmp(&(buf[i]), heredoc->delimiter,
				ft_strlen(heredoc->delimiter)) == 0)
			break ;
		i = 0;
	}
	write(heredoc->pipe_fd[1], "", 1);
	return ((ssize_t)size_read);
}
// Do I really need to do this or do I just dup2 stdin of receiving process??
// void	fprint_heredoc(t_heredoc *heredoc, int write_fd)
// {
// 	char	buf[INT32_MAX];

// 	read(heredoc->pipe_fd[0], buf, INT32_MAX);
	
// }

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