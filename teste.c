/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:08:01 by afonso            #+#    #+#             */
/*   Updated: 2022/12/09 20:04:07 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	char	*line;
	int		exit_status;
	pid_t 	pid;

	pid  = fork();
	line = 0;
	if (pid == 0)
		exit (20);
	else
	{
		waitpid(pid, &errno, WEXITSTATUS(errno));
		printf("errno:%d\n", errno >> 8);
		return (errno >> 8);
	}
}