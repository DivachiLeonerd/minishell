/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:19:46 by afonso            #+#    #+#             */
/*   Updated: 2022/12/23 16:07:47 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

char	**unset(char *variable, char **envp)
{
	char	**name;
	char	**myenvp;
	int		i;

	i = 0;
	name = find_env_full_var(variable, envp);
	if (name == 0)
		return (0);
	else
		myenvp = env_realloc(envp, -1, variable);
	free_env(envp);
	return (myenvp);
}