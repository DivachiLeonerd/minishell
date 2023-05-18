/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:19:46 by afonso            #+#    #+#             */
/*   Updated: 2023/05/17 18:20:11 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"
#include "../../minishell.h"

char	**unset(char **args)
{
	char	**name;
	char	**myenvp;
	char	*variable;

	myenvp = NULL;
	if (!args[1])
	{
		return (g_struct.myenvp);
	}
	variable = args[1];
	name = find_env_full_var(variable);
	if (name == NULL)
		return (g_struct.myenvp);
	else
		g_struct.myenvp = env_realloc(g_struct.myenvp, myenvp, -1, variable);
	return (g_struct.myenvp);
}
