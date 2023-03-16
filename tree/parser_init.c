/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/03/16 20:04:46 by afonso           ###   ########.fr       */
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
	int		i;

	token = 1;
	i = 0;
	if (syntax_checker(s) != 0)
		return (NULL);
	while (tokentype != -1)//this is end of line
	{
		tokens = ft_split(s, ' ');
		if (token_manager(tokens[i++]) == 1)
			token = token_updater(tokens, env);
	//in the future we need to take care of token_manager() == 2
		if (!token)
			break;
		tokentype = get_token_type(token);
		if (tokentype == 6 || tokentype == 4) //token isn't <, >, |, >>
		{
			//pode ser command, built-in, words, heredoc
			token = do_something_with_the_token(token, tokentype, env);// e se esta funçao fosse buscar o args do token?
		}
	}
	return (bintree);
}
