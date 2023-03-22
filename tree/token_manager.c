/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:47 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/03/22 17:07:08 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "parser.h"
#include "./built-ins.h"


//check if there's single/double quotes or '$' (to see 
//if it's a token that needs more attention) 
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

char	**add_argstoken(char **args, char *token)
{
	char	**new_args;
	int		size;
	int     i;
	
	i = -1;
	size = how_many_arrays(args);
	if (!size)
		return (NULL);
	new_args = malloc((size + 2) * sizeof(char *));
	while (args[++i])
		new_args[i] = ft_strdup(args[i]);
	new_args[i] = token;
	new_args[++i] = NULL;
	return (new_args);
}

char      *do_something_with_the_token(char *token, int tokentype, char **env, char **tokens)
{
	char			*new_token;
	t_tree			*bintree;
	static t_tree	*last_node;// guardar o último node q pode aceitar args
	char			**args; //dinamicamente mallocado
	int				i;
	int				temp_tokentype;
	
	i = 0;
	new_token = NULL;
	if (tokentype == 4/*heredoc*/)
	{
		new_token = token_updater(tokens, env);
		temp_tokentype = get_tokentype(new_token);
		last_node->heredoc = make_heredoc();
		last_node->heredoc->delimiter = new_token;//do we even need delimiter member then?
		last_node->heredoc->bytes_stored = get_heredoc_input(last_node->heredoc, new_token);
		return (last_node);
	}
	if (tokentype != /*word*/8 && tokentype != 3/*pipe*/)
	{
		bintree = add_to_tree(tokentype, args);
		last_node = bintree;
		new_token = token_updater(tokens, env);
		temp_tokentype = get_tokentype(new_token);
		while (temp_tokentype == 8)
		{
			if (i == 0)
				add_argstoken(last_node->args, new_token);
			new_token = token_updater(tokens, env);
			temp_tokentype = get_tokentype(new_token);
			if (temp_tokentype != 8)
				return (do_something_with_the_token(new_token, temp_tokentype, env, tokens));
			add_argstoken(last_node->args, token_updater(tokens, env));	
			i++;
		}
		bintree = add_to_tree(tokentype, args);
		last_node = bintree;
	}
	return (bintree);
}