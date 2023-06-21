/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:21:44 by afonso            #+#    #+#             */
/*   Updated: 2023/05/23 17:25:39 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	g_struct.myenvp = build_envp(envp);
	env();
	cd(argv[1], NULL, NULL, NULL);
	printf("\n\nnew_PWD:");
	ft_pwd();
	printf("\n\nCheck new PWD in env:\n\n");
	env();
	free_matrix(g_struct.myenvp);
	return (0);
}
