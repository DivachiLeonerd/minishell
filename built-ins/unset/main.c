/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:50:31 by afonso            #+#    #+#             */
/*   Updated: 2022/12/23 16:09:40 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

int	main(int argc, char **argv, char **envp)
{
	char	**myenvp;
	char	*name = "MYVAR=afonso";
	//tip: only the last variable will change unless the program needs to replace a variable
	printf("Building envp copy\n");
	myenvp = build_envp(envp);
	printf("\n\nPrinting myenvp....\n\n");
	env(myenvp);
	printf("\n\nExporting MYVAR==afonso\n\n");
	myenvp = export(name, myenvp);
	printf("\n\nPrinting myenvp....\n\n");
	env(myenvp);
	printf("\n\nUnsetting MYVAR=afonso\n\n");
	myenvp = unset(name, myenvp);
	printf("\n\nPrinting myenvp....\n\n");
	env(myenvp);
	free_env(myenvp);
	return (0);
}