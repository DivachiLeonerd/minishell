/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:52:06 by afonso            #+#    #+#             */
/*   Updated: 2023/05/23 17:25:53 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	main(int argc, char **argv, char **envp)
{
	if (ft_echo(argv, 0, 0) == 0)
		return (0);
	return (1);
}
