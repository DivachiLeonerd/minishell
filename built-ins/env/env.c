/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:45:50 by afonso            #+#    #+#             */
/*   Updated: 2022/12/14 17:04:41 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

int	env(char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			write(1, &(envp[i][j]), 1);
			j++;
		}
		if (envp[i][j] == 0)
			write(1, "\n", 1);
			// write(1, " **0** ", 7);
		i++;
	}
	return (0);
}