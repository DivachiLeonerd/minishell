/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:27:46 by afonso            #+#    #+#             */
/*   Updated: 2023/05/17 17:19:18 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

int	main(int argc, char **argv, char **envp)
{
	char	**g_struct.myenvp;

	g_struct.myenvp = build_envp(envp);
	ft_pwd(argv, g_struct.myenvp);
	env(g_struct.myenvp);
	cd("../");
	ft_pwd(argv, g_struct.myenvp);
	return (0);
}
