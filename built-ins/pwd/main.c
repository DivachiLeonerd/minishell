/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:27:46 by afonso            #+#    #+#             */
/*   Updated: 2023/05/19 16:34:01 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	main(int argc, char **argv, char **envp)
{
	g_struct.myenvp = build_envp(envp);
	ft_pwd(argv, g_struct.myenvp);
	env(g_struct.myenvp);
	cd("../");
	ft_pwd(argv, g_struct.myenvp);
	return (0);
}
