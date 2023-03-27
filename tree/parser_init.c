/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/03/27 15:55:48 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>

t_tree *parser_init(char *s, char **env)
{
	t_tree	*bintree;
	int		tokentype;
	char	*token;
	char	**tokens;
	int		i;

	token = NULL;
	tokentype = 0;
	i = 0;
	bintree = NULL;
	if (syntax_checker(s) != 0)
		return (NULL);
	printf("passed syntax checker\n");
	tokens = ft_split(s, ' ');
	while (tokentype != -1)//this is end of line
	{
		if (token_manager(tokens[i++]) == 1)//nao gosto do facto de isto ter que correr duas vezes
			token = token_updater(tokens, env);
	//in the future we need to take care of token_manager() == 2
		tokentype = get_token_type(token, env);
		if (!token)
			continue ;
		printf("tokentype=%d\n", tokentype);
		bintree = addtoken_to_tree(token, tokentype, env, tokens);// e se esta funçao fosse buscar o args do token?
		if (chad_exitstatus == 10)//inside add_token()
			break ;
	}
	if (bintree)
	{
		printf("bintree tokentype:%d\n", bintree->tokentype);
		while (bintree->back != NULL)
			bintree = bintree->back;
	}
	free(tokens);
	return (bintree);
}
