/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:25:59 by afonso            #+#    #+#             */
/*   Updated: 2022/12/09 10:21:22 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"


//echo tem que poder usar a flag "-n" que faz com que echo
//não printe \n no final da string escrita
//echo tem de conseguir printar com quotes e single quotes
//e saber printar env vars se tiverem '$' e todos os ficheiros se tiver '*'.

static void	print_env(char **envp)
{
	
}

int	ft_echo(char **argv, char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '$')
			{
				write(1, &argv[i][j], 1);
				i++;
			}
			else
				print_env();
		}
	}
}