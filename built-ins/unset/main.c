/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:50:31 by afonso            #+#    #+#             */
/*   Updated: 2023/05/23 17:13:39 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"
#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*name;

	name = "MYVAR=afonso";
	printf("Building envp copy\n");
	g_struct.myenvp = build_envp(envp);
	printf("\n\nPrinting g_struct.myenvp....\n\n");
	env();
	printf("\n\nExporting MYVAR==afonso\n\n");
	g_struct.myenvp = export(name);
	printf("\n\nPrinting g_struct.myenvp....\n\n");
	env();
	printf("\n\nUnsetting MYVAR=afonso\n\n");
	g_struct.myenvp = unset(name);
	printf("\n\nPrinting g_struct.myenvp....\n\n");
	env();
	free_matrix(g_struct.myenvp);
	return (0);
}
