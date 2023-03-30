/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:24:14 by afonso            #+#    #+#             */
/*   Updated: 2023/03/30 17:50:19 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

void	free_bad_env_build(char **envp, int failed_index)
{
	while (failed_index >= 0)
		free(envp[failed_index--]);
	free(envp);
	return ;
}

int	how_many_arrays(char **double_ptr)
{
	int		i;

	i = 0;
	if (!double_ptr)
		return (0);
	while (double_ptr[i] != NULL)
		i++;
	return (i);
}

char	**build_envp(char **envp)
{
	char	**myenvp;
	int		i;
	int		len;

	i = 0;
	len = how_many_arrays(envp);
	myenvp = malloc((len + 1) * sizeof(char *));
	if (myenvp == NULL)
		return (NULL);
	myenvp[len] = NULL;
	while (i < len)
	{
		myenvp[i] = ft_strdup(envp[i]);
		if (myenvp[i] == NULL)
		{
			free_bad_env_build(myenvp, i);
			return (NULL);
		}
		i++;
	}
	return (myenvp);
}

void	env_realloc(char ***envp,char ***new_env, int	numof_new_arrays, char *var)
{
	int		len;

	printf("in env_realloc():%d\n", numof_new_arrays);
	if (numof_new_arrays == 0)
	{
		*envp = replace_env_var(*envp, var);
		printf("i env_realloc():%s\n", *envp[0]);
		return ;
	}
	len = how_many_arrays(*envp);
	new_env = malloc(((len + 1) + numof_new_arrays) * sizeof(char *));
	if (numof_new_arrays > 0)
		add_var_to_env(*new_env, *envp, var);
	else
		delete_var_from_env(*new_env, *envp, var);
	new_env[len + numof_new_arrays] = NULL;
	envp = new_env;
	return ;
}

void	free_matrix(char **envp)
{
	int	i;
	int	j;

	j = 0;
	i = how_many_arrays(envp);
	while (j < i)
	{
		free(envp[j]);
		j++;
	}
	free(envp);
}
