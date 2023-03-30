/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:21:44 by afonso            #+#    #+#             */
/*   Updated: 2023/03/30 11:43:05 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

int main(int argc, char **argv, char **envp)
{
	char	**myenvp;

	myenvp = build_envp(envp);
	env(myenvp);
	cd(argv[1]);
	printf("\n\nnew_PWD:");
	ft_pwd();
	printf("\n\nCheck new PWD in env:\n\n");
	env(myenvp);
	free_matrix(myenvp);
	return (0);
}