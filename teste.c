/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:08:01 by afonso            #+#    #+#             */
/*   Updated: 2023/05/22 15:50:25 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*homedir_subst(char *pwd)
{
	char *aux;
	size_t	size;
	
	aux = str_expander(ft_strdup("$HOME"));
	if (ft_strncmp(pwd, aux, ft_strlen(aux)) == 0)
	{
		size = ft_strlen(aux);
		free(aux);
		aux = ft_substr(pwd, size, ft_strlen(pwd) - size);
		free(pwd);
		pwd = ft_strjoin("~", aux);
		free(aux);
		return (pwd);
	}
	free(aux);
	return (pwd);
}

char	*print_prompt(int r_flag)
{
	char	*pwd;
	char	*aux;
	char	prompt[200];

	pwd = getcwd(NULL, 0);
	pwd = homedir_subst(pwd);
	aux = ft_strjoin(PROMPT, pwd);
	free(pwd);
	pwd = ft_strjoin(aux, "\033[0m$ ");
	free(aux);
	ft_strlcpy(prompt, pwd, ft_strlen(pwd) + 1);
	free(pwd);
	if (r_flag)
		aux = readline(prompt);
	else
	{
		printf("%s", prompt);
		return (NULL);
	}
	return (aux);
}
g_controller g_struct;
int	main(int argc, char **argv, char **envp)
{
	char	*command_line;
	t_tree	*bintree;
	int		i;
	// int		pid;

	i = 1;
	(void)argc;
	(void)argv;
	g_struct.myenvp = build_envp(envp);
	command_line = NULL;
	//returns a empty string, which is different from a NULL
	while (i)
	{
		bintree = NULL;
		intr_behaviour(&(g_struct.behaviour));
		while (1)
		{
			command_line = print_prompt(1);
			if (!command_line)
			{
				printf("exit\n");
				exit(0);
			}
			if (command_line[0] == '\0')
				free(command_line);
			else
				break ;
		}
		if (ft_strncmp("exit", command_line, 4))
			add_history(command_line);
		else
			i = 0 ;
		if (i == 1)
		{
			//pid = fork();
			// if (pid == 0)
			// {
			// 	nintr_behaviour(&(g_struct.behaviour));
				bintree = parser_init(command_line);
			// }
		}
		// if (pid)
		// {
		// 	g_struct.behaviour.sa_handler = SIG_IGN;
		// 	sigaction(SIGINT, &(g_struct.behaviour), NULL);
		// 	waitpid(pid, NULL, 0);
		// 	free(command_line);
		// 	continue ;
		// }
		if (bintree)
			make_processes(bintree);
		free(command_line);
		command_line = NULL;
		free_tree(bintree);
		if (g_struct.chad_exitstatus != 0 && i == 1)
			printf("status:%s\n", strerror(g_struct.chad_exitstatus));
	}
	free_matrix(g_struct.myenvp);
	exit(0);
	return (0);
}