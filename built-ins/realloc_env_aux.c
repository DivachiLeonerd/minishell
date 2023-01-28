/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_env_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:58:53 by afonso            #+#    #+#             */
/*   Updated: 2023/01/04 18:32:11 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

int	add_var_to_env(char **new_env, char **old_env, char *var)
{
	int i;

	i = 0;
	while (old_env[i])
	{
		new_env[i] = ft_strdup(old_env[i]);
		i++;
	}
	new_env[i] = ft_strdup(var);
	new_env[++i] = NULL; 
	return (0);
}

int	replace_env_var(char **new_env, char **old_env, char *var)
{
	int i;
	char *new_name;

	i = 0;
	new_name = get_variable_name(var);
	while (old_env[i])
	{
		if (ft_strncmp(old_env[i], new_name, ft_strlen(new_name)) == 0)
		{
			new_env[i] = ft_strdup(var);
			i++;
		}
		new_env[i] = ft_strdup(old_env[i]);
		i++;
	}
	new_env[i] = NULL;
	free(new_name);
	return (0);
}

int	delete_var_from_env(char **new_env, char **old_env, char *var)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (old_env[i])
	{
		if (ft_strncmp(old_env[i], var, ft_strlen(var)) == 0)
			i++;
		new_env[j] = ft_strdup(var);
		i++;
		j++;
	}
	return (0);
}