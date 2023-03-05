/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/03/03 19:33:15 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>

//should parser init really build the tree? Maybe delegate that to other function?
t_tree *parser_init(char *s, char **env)
{
	t_tree	*bintree;
	int		tokentype;
	char	*token;
	char	**tokens;

	token = 1;
	if (syntax_checker(s) != 0)
		return (NULL);
	while (tokentype != -1)//this is end of line
	{
		tokens = ft_split(s, ' ');
		token = token_updater(tokens, env);
		if (!token)
			break;
		tokentype = get_token_type(token);
		if (tokentype == 6) //token isn't <, >, |, >>, <<
		{
			//função que verifica se é comando ou built in ou palavra func(token) 
			token = do_something_with_the_token(token, tokentype, env);// e se esta funçao fosse buscar o args do token?
		}
	}
	return tree;
}