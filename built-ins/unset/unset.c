/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:19:46 by afonso            #+#    #+#             */
/*   Updated: 2023/03/30 17:46:40 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

char	**unset(char **args, char **envp)
{
	char	**name;
	char	**myenvp;
	char	*variable;

	myenvp = NULL;
	variable = args[1];
	name = find_env_full_var(variable, envp);
	if (name == 0)
		return (0);
	else
		env_realloc(&envp, &myenvp, -1, variable);
	if (myenvp)
		free_matrix(envp);
	return (myenvp);
}