/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_built-in_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:10:01 by afonso            #+#    #+#             */
/*   Updated: 2023/06/21 14:38:55 by buny             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../minishell.h"

static void	free_all_paths(char **all_paths)
{
	int	i;

	i = 0;
	while (all_paths[i])
		free(all_paths[i++]);
	free(all_paths);
	return ;
}

char	*if_dot_or_slash(char *temp, char *command, struct stat buff)
{
	temp = ft_strdup(command);
	if (access(temp, F_OK) == 0)
	{
		if (access(temp, X_OK) == 0)
		{
			stat(temp, &buff);
			if (S_ISREG(buff.st_mode))
				return (temp);
		}
	}
	g_struct.chad_exitstatus = 13;
	free(temp);
	return (temp = NULL);
}

static char	*get_command_path(char **all_paths, char *temp, char *command_path)
{
	int	i;

	i = 0;
	while (all_paths[i])
	{
		command_path = ft_strjoin(all_paths[i], temp);
		if (access(command_path, F_OK) == 0 && (ft_strnstr(command_path,
					"..", ft_strlen("..")) == 0))
		{
			if (access(command_path, X_OK) == 0)
				return (command_path);
		}
		i++;
		free(command_path);
		command_path = NULL;
	}
	return (NULL);
}

char	*find_command_path(char *command)
{
	int			i;
	char		**all_paths;
	char		*command_path;
	char		*temp;
	struct stat	buff;

	i = 0;
	command_path = NULL;
	if (command[0] == '.' || command[0] == '/')
		return (if_dot_or_slash(NULL, command, buff));
	else
		temp = ft_strjoin("/", command);
	while (ft_strncmp("PATH=", g_struct.myenvp[i], 4) != 0)
		i++;
	all_paths = ft_split(g_struct.myenvp[i], ':');
	i = 0;
	command_path = get_command_path(all_paths, temp, command_path);
	free(temp);
	free_all_paths(all_paths);
	return (command_path);
}

int	execute_non_builtin(char *command_name, char **args)
{
	char	*pathname;

	pathname = find_command_path(command_name);
	free(command_name);
	if (pathname != NULL)
		return (execve(pathname, args, g_struct.myenvp));
	return (127);
}
