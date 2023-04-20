/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:04:42 by afonso            #+#    #+#             */
/*   Updated: 2023/04/03 15:25:10 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "built-ins.h"
#include "piping.h"
#include "../define.h"
#include "../libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	char	**myenvp;

	myenvp = build_envp(envp);
	printf("myenvp:%p\n", myenvp);
	myenvp = export(&(argv[1]), myenvp);
	printf("after export:%p\n", myenvp);
	env(myenvp);
	myenvp = export(&(argv[2]), myenvp);
	printf("after second export:%p\n", myenvp);
	env(myenvp);
	free_matrix(myenvp);
	return (0);
}
