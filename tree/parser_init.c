/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/05/15 11:11:38 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
#include "../minishell.h"

t_tree	*parser_init(char *s, char ***env)
{
	t_tree		*bintree;
	char		**tokens;

	bintree = NULL;
	if (syntax_checker(s) != 0)
		return (NULL);
	tokens = ft_divide_tokens(s, ' ');
	bintree = addtoken_to_tree(*env, tokens);
	bintree = find_topof_tree(bintree);
	free(tokens);
	return (bintree);
}
