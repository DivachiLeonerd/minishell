/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:46:47 by afonso            #+#    #+#             */
/*   Updated: 2023/05/23 17:11:19 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"
#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		j;

	g_struct.myenvp = build_envp(envp);
	g_struct.myenvp = export(&(argv[1]));
	env();
	printf("\n**************\n\n");
	g_struct.myenvp = export(&(argv[2]));
	env();
	free_matrix(g_struct.myenvp);
	return (0);
}
