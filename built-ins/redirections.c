/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:48:03 by afonso            #+#    #+#             */
/*   Updated: 2023/04/23 17:01:37 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piping.h"

int	output_redirection(int fd1, t_tree *node, int token_type)
{
	char	buf[200];
	int		fd2;
	ssize_t	readbytes;

	if (token_type == O_REDIR)
		fd2 = open(node->args[0] /*filename*/, O_CREAT, O_WRONLY);
	else if (token_type == O_APPEND)
		fd2 = open(node->args[0], O_CREAT, O_WRONLY, O_APPEND);
	else
		perror("Token type was neither redirect nor append");
	readbytes = read(fd1, buf, 200);
	if (readbytes == -1)
	{
		perror("Failed read() instruction in redirection");
		return (-1);
	}
	write(fd2, buf, readbytes);
	close(fd2);
	return (0);
}

//input redirection

