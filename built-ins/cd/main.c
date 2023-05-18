/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:21:44 by afonso            #+#    #+#             */
/*   Updated: 2023/05/17 17:19:18 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

int	main(int argc, char **argv, char **envp)
{
	char	**g_struct.myenvp;

	g_struct.myenvp = build_envp(envp);
	env(g_struct.myenvp);
	cd(argv[1]);
	printf("\n\nnew_PWD:");
	ft_pwd();
	printf("\n\nCheck new PWD in env:\n\n");
	env(g_struct.myenvp);
	free_matrix(g_struct.myenvp);
	return (0);
}
