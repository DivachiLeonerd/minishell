/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:21:44 by afonso            #+#    #+#             */
/*   Updated: 2023/01/05 15:11:51 by afonso           ###   ########.fr       */
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
	myenvp = ft_pwd(argv, myenvp);
	printf("\n\nCheck new PWD in env:\n\n");
	env(myenvp);
	free_env(myenvp);
	return (0);
}