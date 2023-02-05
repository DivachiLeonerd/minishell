/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:00:04 by afonso            #+#    #+#             */
/*   Updated: 2023/02/03 13:39:35 by afonso           ###   ########.fr       */
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
		while (line)
		{
			line = readline("minishell:");
			free(line);
			printf("\n");
		}
		add_history(line);
	}
	return (0);
}