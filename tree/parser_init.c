/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/04/15 11:03:34 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
#include "../minishell.h"

t_tree *parser_init(char *s, char ***env)
{
	t_tree			*bintree;
	char			**tokens;

	bintree = NULL;
	if (syntax_checker(s) != 0)
		return (NULL);
	tokens = ft_split(s, ' ');
	bintree = addtoken_to_tree(*env, tokens);
	// printf("%s\n", bintree->args[0]);
	// printf("%s\n", bintree->args[1]);
	// if (chad_exitstatus == 10) inside add_token()
	bintree = find_topof_tree(bintree);
	free(tokens);
	return (bintree);
}
