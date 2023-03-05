/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:00:04 by afonso            #+#    #+#             */
/*   Updated: 2023/03/01 10:57:23 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int argc, char **argv, char **envp)
{
	int		*exit_status;
	pid_t	pid;
	char	*line;
	int		command_num;

	exit_status = 0; // Isto é o "$?, provavelmente será uma global no header file"
	line = 1;
	while (1)
	{
		while (line)
		{
			line = readline("minishell: ");
			printf("\n");
		}
		add_history(line);
		free(line);
	}
	return (0);
}