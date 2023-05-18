/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:19:46 by afonso            #+#    #+#             */
/*   Updated: 2023/05/18 17:46:56 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"
#include "../../minishell.h"

int	unset(char **args)
{
	char	**name;
	char	**myenvp;
	char	*variable;

	myenvp = NULL;
	if (!args[1])
		return (0);
	variable = args[1];
	name = find_env_full_var(variable);
	if (name == NULL)
		return (0);
	else
		g_struct.myenvp = env_realloc(g_struct.myenvp, myenvp, -1, variable);
	return (errno);
}
