/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:52:06 by afonso            #+#    #+#             */
/*   Updated: 2023/01/03 14:25:39 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

int main(int argc, char **argv, char **envp)
{
	if (ft_echo(argv[1], envp, 0) == 0)
		return (0);
	return (1);
}