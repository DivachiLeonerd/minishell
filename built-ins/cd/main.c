/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:21:44 by afonso            #+#    #+#             */
/*   Updated: 2023/01/04 15:06:24 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

int main(int argc, char **argv, char **envp)
{
	char	**myenvp;

	myenvp = build_envp(envp);
	env(myenvp);
	cd(argv[1]);
	printf("So para ver se ta bem\n");
	ft_pwd(argv, myenvp);
	free_env(myenvp);
	return (0);
}