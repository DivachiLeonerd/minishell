/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:05:47 by afonso            #+#    #+#             */
/*   Updated: 2023/03/27 12:32:58 by atereso-         ###   ########.fr       */
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

	variable = args[1];
	var = find_env_full_var(variable, myenvp);
	new_var = ft_strdup(variable);
	if (var == NULL)//if var not found
		new_env = env_realloc(myenvp, 1, variable);
	else
		new_env = env_realloc(myenvp, 0, variable);
	free_matrix(myenvp);
	free(new_var);
	return (new_env);
}