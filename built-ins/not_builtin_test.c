/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_builtin_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:04:42 by afonso            #+#    #+#             */
/*   Updated: 2023/01/03 12:00:16 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

int	main(int argc, char **argv, char **envp)
{
	char	**myenvp;
	int		i;

	myenvp = build_envp(envp);
	execute_non_builtin("mv", myenvp, argv);// when testing only put arguments in command line
	free_env(myenvp);						//e.g: ./executable ../apontamento.txt ./
	printf("nice\n");
	return (0);
}