/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:00:04 by afonso            #+#    #+#             */
/*   Updated: 2023/04/14 12:09:32 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		*exit_status;
	pid_t	pid;
	char	*line;
	int		command_num;

	exit_status = 0; // Isto é o "$?, provavelmente será uma global no header file"
	line = 1;
	while (1)
	{
		while (!line)
		{
			line = readline("minishell: ");
			printf("\n");
		}
		add_history(line);
		free(line);
	}
	return (0);
}
