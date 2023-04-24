/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:08:01 by afonso            #+#    #+#             */
/*   Updated: 2023/04/23 16:55:02 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*print_prompt(char **myenvp)
{
	char	*pwd;
	char	*aux;
	size_t	size;

	pwd = ft_pwd();
	printf("\033[1;32m");
	printf(PROMPT);
	printf("\033[1;34m");
	aux = str_expander(ft_strdup("$HOME"), myenvp);
	if (ft_strncmp(pwd, aux, ft_strlen(aux)) == 0)
	{
		size = ft_strlen(aux);
		free(aux);
		aux = ft_substr(pwd, size, ft_strlen(pwd) - ft_strlen(aux));
		free(pwd);
		pwd = ft_strjoin("~", aux);
		free(aux);
	}
	printf("%s\033[0m$", pwd);
	aux = readline(" ");
	free(pwd);
	return (aux);
}
int chad_exitstatus = 0;
int	main(int argc, char **argv, char **envp)
{
	t_tree				*monotree;
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
		monotree = NULL;
		intr_behaviour(&behaviour);
		while (1)
		{
			command_line = print_prompt(myenvp);
			if (!command_line)
			{
				printf("exit\n");
				exit(0);//maybe in the furture we discard exit() here and return normally
			}
			if (command_line[0] == '\0')
				free(command_line);
			else
				break ;
		}
		if (ft_strncmp("exit", command_line, 4) != 0)
			add_history(command_line);
		else
			i = 0 ;
		if (i == 1)
		{
			nintr_behaviour(&behaviour);
			monotree = parser_init(command_line, &myenvp);
		}
		if (monotree)
			myenvp = tree_execution(monotree);
		free(command_line);
		command_line = NULL;
		free_tree(monotree);
	}
	free_matrix(myenvp);
	exit(0);
	return (0);
}