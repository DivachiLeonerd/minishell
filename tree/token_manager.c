/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:47 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/02/28 18:00:12 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "parser.h"

int    *token_manager(char *token)
{
	int     i;
	int     dollar_sign;
	int     single_quote;
	int     double_quote;

	if (!token)
		return (0);
	i = 0;
	dollar_sign = 0;
	single_quote = 0;
	double_quote = 0;
	while (token[i])
	{
		if (token[i] == '\'')
			single_quote++;
		else if (token[i] == '\"')
			double_quote++;
		else if (token[i] == '$')
			dollar_sign++;
		i++;
	}
	if (single_quote > 1 || double_quote > 1 || dollar_sign > 0)
		return (1);
	else if (single_quote == 1 || double_quote == 1)
		return (2);
	return (0);
}

char      *do_something_with_the_token(char *token, int tokentype, t_list *env)
{
	char	*new_token;
	t_tree	*bintree;

	if (!token_manager)
		return token;
	new_token = NULL;
	new_token = token_updater(token, env); //stupid name up for debate
	bintree = add_to_tree(tokentype, args);
	return (new_token);
}

