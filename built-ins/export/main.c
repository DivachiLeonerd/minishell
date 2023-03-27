/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:46:47 by afonso            #+#    #+#             */
/*   Updated: 2023/03/27 12:33:01 by atereso-         ###   ########.fr       */
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
	free_matrix(myenvp);
	return (0);
}