/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:44:37 by afonso            #+#    #+#             */
/*   Updated: 2023/04/03 17:06:25 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

//the purpose of this function will be to receive the binary tree output and put it in the 
//appropriate functions

int	is_builtin(char *command)
{
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

void	execute_builtin(char *command, char **myenvp, char **args)
{
	char *str;

	if (ft_strncmp("echo", command, ft_strlen("echo")) == 0)
		ft_echo(args);
	if (ft_strncmp("env", command, ft_strlen("env")) == 0)
		env(myenvp);
	// if (ft_strncmp("cd", command, ft_strlen("cd")) == 0)
	// 	cd(args[1], myenvp);
	if (ft_strncmp("pwd", command, ft_strlen("pwd")) == 0)
	{
		str = ft_pwd();
		printf("%s\n", str);
		free(str);		
	}
	// if (ft_strncmp("unset", command, ft_strlen("unset")) == 0)
	// 	unset(args, myenvp);
	return ;
}
