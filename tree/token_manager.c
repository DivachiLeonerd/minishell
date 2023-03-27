/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:47 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/03/27 23:33:04 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "parser.h"
#include "../built-ins/built-ins.h"


//check if there's single/double quotes or '$' (to see 
//if it's a token that needs more attention) 
int	token_manager(char *token)
{
	int     i;
	int     dollar_sign;
	int     single_quote;
	int     double_quote;

	if (!token)
		return (1);
	i = 0;
	dollar_sign = 0;
	single_quote = 0;
	double_quote = 0;
	// printf("in token_manager():token:%p\n", token);
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
	return (1);
}

char	**add_argstoken(char **args, char *token)
{
	char	**new_args;
	int		size;
	int     i;
	
	i = 0;
	size = how_many_arrays(args);
	printf("in add_argstoken:args_size:%d\n", size);
	new_args = malloc((size + 2) * sizeof(char *));//its plus NULL termination and new arg
	while (args && i < size)
	{
		printf("i:%d\n", i);
		new_args[i] = ft_strdup(args[i]);
		i++;
	}
	new_args[i] = token;
	new_args[++i] = NULL;
	printf("in add_argstoken():args[0]:%s\n", new_args[0]);
	if (size)
		free_matrix(args);
	return (new_args);
}

t_tree	*addtoken_to_tree(char *token, int tokentype, char **env, char **tokens)
{
	char			*new_token;
	static t_tree	*last_node;// guardar o último node q pode aceitar args
	char			**args; //dinamicamente mallocado
	int				i;
	int				temp_tokentype;
	
	i = 0;
	temp_tokentype = 0;
	args = NULL;
	new_token = NULL;
	if (tokentype == HEREDOC)
	{
		new_token = token_updater(tokens, env);
		temp_tokentype = get_token_type(new_token, env);
		last_node->heredoc = make_heredoc();
		last_node->heredoc->delimiter = new_token;//do we even need delimiter member then?
		last_node->heredoc->bytes_stored = get_heredoc_input(last_node->heredoc, new_token);
		return (last_node);
	}
	if (tokentype != WORD && tokentype != HEREDOC && tokentype != PIPE && tokentype > 0)
	{
		last_node = add_to_tree(tokentype, args);
		if (tokentype == BUILTIN || tokentype == EXECUTABLE)
			last_node->args = add_argstoken(last_node->args, token);
		printf("inside addtoken_to_tree():last_nodeargs:%s\n", (last_node->args)[0]);
		new_token = token_updater(tokens, env);
		printf("in addtoken_to_tree():new_token:%s\n", new_token);
		temp_tokentype = get_token_type(new_token, env);
		printf("in the same func:tokentype:%d\n", temp_tokentype);
		while (temp_tokentype == WORD)
		{
			if (i == 0)
				last_node->args = add_argstoken(last_node->args, new_token);
			new_token = token_updater(tokens, env);
			temp_tokentype = get_token_type(new_token, env);
			if (temp_tokentype != WORD)
				return (addtoken_to_tree(new_token, temp_tokentype, env, tokens));
			add_argstoken(last_node->args, token_updater(tokens, env));	
			i++;
		}
		last_node = add_to_tree(temp_tokentype, args);
	}
	if (token)
		free(token);
	return (last_node);
}