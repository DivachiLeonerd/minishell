/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:19:46 by afonso            #+#    #+#             */
/*   Updated: 2023/05/09 19:27:09 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

char	**unset(char **args, char **envp)
{
	char	**name;
	char	**myenvp;
	char	*variable;

	myenvp = NULL;
	if (!args[1])
	{
		return (envp);
	}
	variable = args[1];
	name = find_env_full_var(variable, envp);
	if (name == NULL)
		return (envp);
	else
		myenvp = env_realloc(envp, myenvp, -1, variable);
	return (myenvp);
}
