/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:50:31 by afonso            #+#    #+#             */
/*   Updated: 2023/05/17 17:19:18 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

int	main(int argc, char **argv, char **envp)
{
	char	**g_struct.myenvp;
	char	*name;

	name = "MYVAR=afonso";
		//tip: only the last variable will change unless the program
		//needs to replace a variable
	printf("Building envp copy\n");
	g_struct.myenvp = build_envp(envp);
	printf("\n\nPrinting g_struct.myenvp....\n\n");
	env(g_struct.myenvp);
	printf("\n\nExporting MYVAR==afonso\n\n");
	g_struct.myenvp = export(name, g_struct.myenvp);
	printf("\n\nPrinting g_struct.myenvp....\n\n");
	env(g_struct.myenvp);
	printf("\n\nUnsetting MYVAR=afonso\n\n");
	g_struct.myenvp = unset(name, g_struct.myenvp);
	printf("\n\nPrinting g_struct.myenvp....\n\n");
	env(g_struct.myenvp);
	free_matrix(g_struct.myenvp);
	return (0);
}
