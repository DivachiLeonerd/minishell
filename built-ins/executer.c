/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:44:37 by afonso            #+#    #+#             */
/*   Updated: 2023/04/20 17:25:26 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

//the purpose of this function will be to receive the binary 
//tree output and put it in the appropriate functions

int	is_builtin(char *command)
{
	// printf("in is_builtin\n");
	if (ft_strncmp("echo", command, ft_strlen("echo")) == 0
		|| ft_strncmp("env", command, ft_strlen("env")) == 0
		|| ft_strncmp("exit", command, ft_strlen("exit")) == 0
		|| ft_strncmp("export", command, ft_strlen("export")) == 0
		|| ft_strncmp("cd", command, ft_strlen("cd")) == 0
		|| ft_strncmp("pwd", command, ft_strlen("pwd")) == 0
		|| ft_strncmp("unset", command, ft_strlen("unset")) == 0)
		return (1);
	return (0);
}

void	execute_builtin(char *command, char **myenvp __attribute__((unused)),
		char **args)
{
	char	*str;

	if (ft_strncmp("echo", command, ft_strlen("echo")) == 0)
		ft_echo(args);
	else if (ft_strncmp("env", command, ft_strlen("env")) == 0)
		env(myenvp);
	else if (ft_strncmp("cd", command, ft_strlen("cd")) == 0)
		myenvp = cd(args[1], myenvp);
	else if (ft_strncmp("pwd", command, ft_strlen("pwd")) == 0)
	{
		str = ft_pwd();
		printf("%s\n", str);
		free(str);
	}
	else if (ft_strncmp("export", command, ft_strlen("export")) == 0)
		myenvp = export(args, myenvp);
	else if (ft_strncmp("unset", command, ft_strlen("unset")) == 0)
		myenvp = unset(args, myenvp);
	return ;
}
