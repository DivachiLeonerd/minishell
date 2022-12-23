/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:00:04 by afonso            #+#    #+#             */
/*   Updated: 2022/12/10 11:27:24 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int argc, char **argv, char **envp)
{
	int		*exit_status;
	pid_t	pid;
	char	*line;
	int		command_num;

	exit_status = 0; // Isto é o "$?"
	while (1)
	{
		while (!line || line[0] == 0)
		{
			line = readline("minishell:");
			free(line);
			printf("\n");
		}
		add_history(line);
	}
	return (0);
}