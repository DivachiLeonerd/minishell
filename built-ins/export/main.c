/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:46:47 by afonso            #+#    #+#             */
/*   Updated: 2022/12/23 19:37:17 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

int	main(int argc, char **argv, char **envp)
{
	char	**myenvp;
	int		i;
	int		j;

	myenvp = build_envp(envp);
	myenvp = export(argv[1], myenvp);
	env(myenvp);
	printf("\n**************\n\n");
	myenvp = export(argv[2], myenvp);
	env(myenvp);
	free_env(myenvp);
	return (0);
}