/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:19:46 by afonso            #+#    #+#             */
/*   Updated: 2023/03/27 12:33:07 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

char	**unset(char **args, char **envp)
{
	char	**name;
	char	**myenvp;
	char	*variable;

	variable = args[1];
	name = find_env_full_var(variable, envp);
	if (name == 0)
		return (0);
	else
		myenvp = env_realloc(envp, -1, variable);
	free_matrix(envp);
	return (myenvp);
}