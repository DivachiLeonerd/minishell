/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/04/24 14:47:21 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
#include "../minishell.h"

t_tree	*parser_init(char *s, char ***env)
{
	t_tree		*monotree;
	char		**tokens;
	int			i;

	i = 0;
	monotree = NULL;
	tokens = ft_divide_tokens(s, ' ');
	while (syntax_error(syntax_checker(get_token_type(tokens[i++], env))) == 0)
		;
	if (tokens[i] != NULL)
	{
		free_matrix(tokens);
		return (NULL);
	}
	monotree = addtoken_to_tree(*env, tokens);
	free(tokens);
	return (monotree);
}
