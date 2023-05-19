/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/05/19 20:07:25 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
#include "../minishell.h"

t_tree	*parser_init(char *s)
{
	// int			i;
	t_tree		*bintree;
	char		**tokens;
	
	// i = 0;
	bintree = NULL;
	if (syntax_checker(s) != 0)
		return (NULL);
	tokens = ft_divide_tokens(s, ' ');
	if (tokens[0][0] == '|')
		return (NULL);
	// if (validate_commands(tokens))
	// {
	// 	g_struct.chad_exitstatus = 127;
	// 	return (NULL);
	// }
	bintree = addtoken_to_tree(tokens);
	bintree = find_topof_tree(bintree);
	free(tokens);
	return (bintree);
}
