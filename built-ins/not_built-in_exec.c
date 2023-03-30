/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_built-in_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:10:01 by afonso            #+#    #+#             */
/*   Updated: 2023/03/30 15:53:16 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

static void	free_all_paths(char **all_paths)
{
	int	i;

	i = 0;
	while (all_paths[i])
		free(all_paths[i++]);
	free(all_paths);
	return ;
}

char *find_command_path(char **myenvp, char *command)
{
	int		i;
	char	**all_paths;
	char	*command_path;
	char	*temp;

	i = 0;
	while (ft_strncmp("PATH=", myenvp[i], 4) != 0)
		i++;
	all_paths = ft_split(myenvp[i], ':');
	i = 0;
	temp = ft_strjoin("/", command);
	while (all_paths[i])
	{
		command_path = ft_strjoin(all_paths[i], temp);
		if (access(command_path, F_OK) == 0)
		{
			// printf("o comando existe\n");
			if (access(command_path, X_OK) == 0)
			{
				// printf("e é executavel\n");
				break ;
			}
			// perror("Permission denied\n");
		}
		i++;
		free(command_path);
		command_path = NULL;
	}
	free(temp);
	// if (command_path == NULL)
		// perror("command not found\n");
	free_all_paths(all_paths);
	// printf("in find_command_path():%s\n", command_path);
	return (command_path);
}

int execute_non_builtin(char *command_name, char **myenvp, char **args)
{
	char	*pathname;

	pathname = find_command_path(myenvp, command_name);
	if (pathname != NULL)
		execve(pathname, args, myenvp);//execve should free all memory from process after running
	perror("Couldn't find command");
	return -1;
}
