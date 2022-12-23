/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:05:47 by afonso            #+#    #+#             */
/*   Updated: 2022/12/23 15:57:21 by afonso           ###   ########.fr       */
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

char	**export(char *variable, char **envp)
{
	//variable == "NAME=VALUE"
	int 	i;
	int		j;
	char	**var;
	char	*new_var;
	char	**new_env;

	i = 0;
	var = find_env_full_var(variable, envp);
	new_var = malloc(ft_strlen((variable) + 1) * sizeof(char));
	ft_strlcpy(new_var, variable, ft_strlen(variable) + 1);
	i = how_many_arrays(envp);
	if (var == NULL)//if var not found
		new_env = env_realloc(envp, 1, variable);
	else
		new_env = env_realloc(envp, 0, variable);
	free_env(envp);
	free(new_var);
	return (new_env);
}