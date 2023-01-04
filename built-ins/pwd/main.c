/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:27:46 by afonso            #+#    #+#             */
/*   Updated: 2022/12/19 11:44:30 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

int main(int argc, char **argv, char **envp)
{
	char	**myenvp;

	myenvp = build_envp(envp);
	ft_pwd(argv, myenvp);
	env(myenvp);
	cd("../");
	ft_pwd(argv, myenvp);
	return (0);
}