/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:08:01 by afonso            #+#    #+#             */
/*   Updated: 2023/06/02 18:22:54 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*homedir_subst(char *pwd)
{
	char	*aux;
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
t_controller	g_struct;

static char	*small_main_loop(char **command_line)
{
	*command_line = print_prompt(1);
	if (!(*command_line))
	{
		printf("exit\n");
		exit(0);
	}
	if ((*command_line)[0] == '\0')
		free(*command_line);
	else
		return (*command_line);
	return (NULL);
}
t_controller	g_struct;

void	not_so_small_main_loop(int i, char *command_line, t_tree *bintree)
{
	while (i)
	{
		bintree = NULL;
		intr_behaviour(&(g_struct.behaviour));
		while (1)
		{
			if (small_main_loop(&command_line) != NULL)
				break ;
		}
		if (ft_strncmp("exit", command_line, 4))
			add_history(command_line);
		else
			i = 0 ;
		if (i == 1)
				bintree = parser_init(command_line);
		if (bintree)
			make_processes(bintree);
		free(command_line);
		command_line = NULL;
		free_tree(bintree);
		if (g_struct.chad_exitstatus != 0 && i == 1)
			printf("status:%s\n", strerror(g_struct.chad_exitstatus));
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*command_line;
	t_tree	*bintree;
	int		i;

	i = 1;
	(void)argc;
	(void)argv;
	g_struct.myenvp = build_envp(envp);
	command_line = NULL;
	bintree = NULL;
	not_so_small_main_loop(i, command_line, bintree);
	free_matrix(g_struct.myenvp);
	exit(0);
	return (0);
}
