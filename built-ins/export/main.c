/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:46:47 by afonso            #+#    #+#             */
/*   Updated: 2023/05/17 17:19:18 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

int	main(int argc, char **argv, char **envp)
{
	char	**g_struct.myenvp;
	int		i;
	int		j;

	g_struct.myenvp = build_envp(envp);
	g_struct.myenvp = export(&(argv[1]), g_struct.myenvp);
	env(g_struct.myenvp);
	printf("\n**************\n\n");
	g_struct.myenvp = export(&(argv[2]), g_struct.myenvp);
	env(g_struct.myenvp);
	free_matrix(g_struct.myenvp);
	return (0);
}
