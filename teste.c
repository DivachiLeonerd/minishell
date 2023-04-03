/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:08:01 by afonso            #+#    #+#             */
/*   Updated: 2023/04/03 17:58:31 by atereso-         ###   ########.fr       */
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

char	*print_prompt(void)
{
	char	*pwd;
	char	*aux;

	pwd = ft_pwd();
	aux = ft_strjoin(PROMPT, pwd);
	free(pwd);
	pwd = ft_strjoin(aux, "$ ");
	free(aux);
	aux = readline(pwd);
	free(pwd);
	return (aux);
}

int	main(int argc, char **argv, char **envp)
{
	t_tree				*bintree;
	char				**myenvp;
	char				*command_line;
	struct sigaction	behaviour;
	int					i;

	i = 1;
	(void)argc;
	(void)argv;
	
	myenvp = build_envp(envp);
	command_line = NULL;
	//returns a empty string, which is different from a NULL
	while (i)
	{
		intr_behaviour(&behaviour);
		while (1)
		{
			command_line = print_prompt();
			if (command_line[0] == '\0')
				free(command_line);
			else
				break ;
		}
		if (ft_strncmp("exit", command_line, 4))
			add_history(command_line);
		else
			i = 0;
		nintr_behaviour(&behaviour);
		bintree = parser_init(command_line, &myenvp);
		if (!bintree)
		{
			errno = 30;
			// perror("Command not found.");
		}
		else
			myenvp = make_pipes(bintree, myenvp);//command_line a ser executado
		free(command_line);
		command_line = NULL;
		free_tree(bintree);
		// printf("\n");
	}
	free_matrix(myenvp);
	exit(0);
	return (0);
}