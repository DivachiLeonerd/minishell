/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:24:14 by afonso            #+#    #+#             */
/*   Updated: 2023/01/04 15:04:41 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

//cenas para a norminette
int	how_many_arrays(char **double_ptr)
{
	int		i;

	i = 0;
	while (double_ptr[i] != NULL)
	{
		printf("i:%d\n", i);
		i++;
	}
	return (i);
}

char	**build_envp(char **envp)
{
	char	**myenvp;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = how_many_arrays(envp) + 1;
	myenvp = malloc(len * sizeof(char *));
	if (myenvp == NULL)
		return (NULL);
	myenvp[len - 1] = NULL;
	while (i < len - 1)
	{
		myenvp[i] = ft_strdup(envp[i]);
		if (myenvp[i] == 0)
			return (NULL);//fazer funcao free dinamica
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
	new_env = malloc((len + 1 + numof_new_arrays) * sizeof(char *));
	if (numof_new_arrays > 0)
		add_var_to_env(new_env, envp, var);
	else if (numof_new_arrays == 0)
		replace_env_var(new_env, envp, var);
	else
		delete_var_from_env(new_env, envp, var);
	new_env[len + numof_new_arrays] = NULL;
	return (new_env);
}

void	free_env(char **envp)
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