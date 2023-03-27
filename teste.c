/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:08:01 by afonso            #+#    #+#             */
/*   Updated: 2023/03/27 15:13:03 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Ignore this file for now
// int main(void)
// {
// 	char	*line;
// 	int		exit_status;
// 	pid_t 	pid;

// 	pid  = fork();
// 	line = 0;
// 	if (pid == 0)
// 		exit (20);
// 	else
// 	{
// 		waitpid(pid, &errno, WEXITSTATUS(errno));
// 		printf("errno:%d\n", errno >> 8);
// 		return (errno >> 8);
// 	}
// }

int	main(int argc, char **argv, char **envp)
{
	t_tree				*bintree;
	char				**myenvp;
	char				*command_line;
	struct sigaction	behaviour;

	(void)argc;
	(void)argv;
	
	myenvp = build_envp(envp);
	command_line = NULL;
	//returns a empty string, which is different from a NULL
	intr_behaviour(&behaviour);
	command_line = readline(PROMPT);
	while (1)
	{
		chad_exitstatus = 0;
		while (command_line[0] == 0)
		{
			command_line[0] == 0?free(command_line):printf("\n");
			command_line = readline(PROMPT);
		}
		ft_strncmp("exit", command_line, 4)?add_history(command_line):exit(0);
		printf("beginning parsing...\n");
		nintr_behaviour(&behaviour);
		bintree = parser_init(command_line, myenvp);
		if (!bintree)
		{
			errno = 30;
			perror("Bad tree build. Exiting...");
		}
		else
			make_pipes(bintree, myenvp);//command_line a ser executado
		free(command_line);
		printf("\n");
		break ;
	}
	free_matrix(myenvp);
	if (bintree)
	{
		printf("bintree n e nula\n");
		free_tree(bintree);
	}
	return (0);
}