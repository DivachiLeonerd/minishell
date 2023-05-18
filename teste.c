/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:08:01 by afonso            #+#    #+#             */
/*   Updated: 2023/05/18 19:37:30 by atereso-         ###   ########.fr       */
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
// static	void	print_tree_leftbranch(t_tree *bintree)
// {
// 	t_tree *tree;

// 	tree = bintree;
// 	while (tree != NULL)
// 	{
// 		printf("******************************");
// 		if (tree->args)
// 			printf("%s_node:******************************\n", tree->args[0]);
// 		printf("tree_tokentype:%d\n", tree->tokentype);
// 		if (tree->back && tree->back->args)
// 			printf("node->back:%s\n", tree->back->args[0]);
// 		else if (tree->back)
// 			printf("node->back:%p, tokentype:%d\n", tree->back, tree->back->tokentype);
// 		if (tree->left_branch && tree->left_branch->args)
// 		printf("tree->left_branch:%s\n", tree->left_branch->args[0]);
// 		if (tree->right_branch && tree->right_branch->args)
// 			printf("tree->right_branch:%s\n", tree->right_branch->args[0]);
// 		printf("************************************************************\n");
// 		tree = tree->left_branch;
// 	}
// 	return ;
// }

char	*print_prompt(int r_flag)
{
	char	*pwd;
	char	*aux;
	size_t	size;
	int		len;

	pwd = getcwd(NULL, 0);
	printf("\033[1;32m");
	printf(PROMPT);
	printf("\033[1;34m");
	aux = str_expander(ft_strdup("$HOME"));
	if (ft_strncmp(pwd, aux, ft_strlen(aux)) == 0)
	{
		size = ft_strlen(aux);
		len = ft_strlen(aux);
		free(aux);
		aux = ft_substr(pwd, size, ft_strlen(pwd) - len);
		free(pwd);
		pwd = ft_strjoin("~", aux);
		free(aux);
	}
	printf("%s\033[0m$", pwd);
	free(pwd);
	if (r_flag)
		aux = readline(" ");
	else
		return (NULL);
	return (aux);
}
g_controller g_struct;
int	main(int argc, char **argv, char **envp)
{
	t_tree				*bintree;
	char				*command_line;
	int					i;

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
			bintree = parser_init(command_line);
		if (bintree)
			g_struct.myenvp = make_processes(bintree);
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