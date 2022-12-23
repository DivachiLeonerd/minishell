/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:24:14 by afonso            #+#    #+#             */
/*   Updated: 2022/12/23 19:36:00 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

//cenas para a norminette
int	how_many_arrays(char **double_ptr)
{
	int		i;

	i = 0;
	while (double_ptr[i] != NULL)
		i++;
	return (i);
}

char	**build_envp(char **envp)
{
	char	**myenvp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	myenvp = NULL;
	myenvp = malloc(72 * sizeof(char **));
	if (myenvp == NULL)
		return (NULL);
	myenvp[71] = NULL;
	while (envp[i])
	{
		myenvp[i] = malloc(ft_strlen(envp[i] + 1) * sizeof(char *));
		if (myenvp[i] == 0)
			return (NULL);
		ft_strlcpy(myenvp[i], envp[i], ft_strlen(envp[i]) + 1);
		i++;
	}
	return (myenvp);
}

char	**env_realloc(char **envp, int	numof_new_arrays, char *var)
{
	int		i;
	int		j;
	char	**new_env;
	int		len;
	i = 0;
	len = how_many_arrays(envp);
	new_env = malloc((len + 1 + numof_new_arrays) * sizeof(char **));
	new_env[len + numof_new_arrays] = 0;
	if (numof_new_arrays > 0)
		add_var_to_env(new_env, envp, var);
	else if (numof_new_arrays == 0)
		replace_env_var(new_env, envp, var);
	else
		delete_var_from_env(new_env, envp, var);
	return (new_env);
}

void	free_env(char **envp)
{
	int	i;
	int	j;

	i = how_many_arrays(envp);
	while (i > -1)
	{
		free(envp[i]);
		i--;
	}
	free(envp);
}