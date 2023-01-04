/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:44:37 by afonso            #+#    #+#             */
/*   Updated: 2023/01/03 10:33:15 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"

//the purpose of this function will be to receive the binary tree output and put it in the 
//appropriate functions

int	is_builtin(char *command)
{
	if (ft_strncmp("echo", command, ft_strlen("echo")) == 0
		|| ft_strncmp("env", command, ft_strlen("env")) == 0
		|| ft_strncmp("exit", command, ft_strlen("exit")) == 0
		|| ft_strncmp("export", command, ft_strlen("export")) == 0
		|| ft_strncmp("cd", command, ft_strlen("cd")) == 0
		|| ft_strncmp("pwd", command, ft_strlen("pwd")) == 0
		|| ft_strncmp("unset", command, ft_strlen("unset")) == 0)
		return (1);
	return (0);
}

// void	*executer(int command, char *input, void *bin_tree, void *first_node)
// {
// 		if (command tem redirect)
// 			redirect(IO, file);
// 		if (command tem pipe)
// 			buf = do_pipe(command A, command B);
// 		bin_tree = get_next_node();
// 		if (tree ainda n acabou)
// 			return (executer(next_command, buf, bin_tree));
// 	return (estado_de_sucesso);
// }