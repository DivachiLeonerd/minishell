/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:05:47 by afonso            #+#    #+#             */
/*   Updated: 2023/03/30 17:55:40 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

// int	get_env_fd(char **envp)
// {
// 	int fd;
// 	if (access("/usr/local/bin", F_OK) == 0)
// 	{
// 		if (access("/usr/local/bin", W_OK) == 0 && access("/usr/local/bin", R_OK) == 0)
// 			fd = open("/usr/local/bin", O_RDWR);
// 	}
// 	return (fd);
// }

char	**export(char **args, char **myenvp)
{
	//variable == "NAME=VALUE"
	char	*variable;
	char	**var;
	char	*new_var;
	char	**new_env;

	new_env = NULL;
	variable = args[0];
	var = find_env_full_var(variable, myenvp);
	new_var = ft_strdup(variable);
	if (var == NULL)//if var not found
		env_realloc(&myenvp, &new_env, 1, variable);
	else
		env_realloc(&myenvp, &new_env, 0, variable);
	if (new_env)
	{
		printf("in export(): IM FREEING ENVP\n");
		free_matrix(myenvp);
		new_env = myenvp;
	}
	free(new_var);
	return (new_env);
}