/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/04/04 20:25:29 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
#include "../minishell.h"

t_tree *parser_init(char *s, char ***env)
{
	t_tree			*bintree;
	int				tokentype;
	char			*token;
	char			**tokens;
	t_tree			*last_node[1];
	int				i;

	i = 0;
	token = NULL;
	tokentype = 0;
	bintree = NULL;
	*last_node = NULL;
	if (syntax_checker(s) != 0)
		return (NULL);
	tokens = ft_split(s, ' ');
	while (tokentype != -1)//this is end of line
	{
		// if (token_manager(tokens[i++]) == 1)//nao gosto do facto de isto ter que correr duas vezes
		token = token_updater(tokens, *env, &i);
	//in the future we need to take care of token_manager() == 2
		if (!token)
			break ;
		tokentype = get_token_type(token, *env);
		// printf("in parser_init():tokentype=%d\n", tokentype);
		bintree = addtoken_to_tree(token, tokentype, *env, tokens, last_node, &i);// e se esta funçao fosse buscar o args do token?
		printf("bintree-args:%p\n", bintree->left_branch);
		if (chad_exitstatus == 10)//inside add_token()
			break ;
	}
	if (bintree)
	{
		while (bintree->back != NULL)
			bintree = bintree->back;
	}
	free(tokens);
	*last_node = NULL;
	i = 0;
	return (bintree);
}
