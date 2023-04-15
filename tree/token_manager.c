/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:47 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/04/15 11:26:41 by atereso-         ###   ########.fr       */
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
	// printf("in add_argstoken:args_size:%d\n", size);
	new_args = malloc((size + 2) * sizeof(char *));//its plus NULL termination and new arg
	while (args && i < size)
	{
		new_args[i] = ft_strdup(args[i]);
		// printf("in add_argstoken:token:%s\n", new_args[i]);
		i++;
	}
	new_args[i] = token;
	new_args[++i] = NULL;
	// printf("in add_argstoken():args[i]:%s\n", new_args[i - 1]);
	if (size)
		free_matrix(args);
	return (new_args);
}

static void addtoken_heredoc(char **env, char *token, char **tokens, int *controller, t_tree *last_node)
{
	//token == "<<"
	free(token);
	//put heredoc in last_node with next token as delimiter
	token = token_updater(tokens, env, controller);
	// printf("in addtoken_to_tree():heredoc:%s\n", token);
	last_node->heredoc = make_heredoc();
	last_node->heredoc->bytes_stored = get_heredoc_input(last_node->heredoc, token);
	free(token);
	return ;
}

static void addtoken_words(char *token, t_tree *last_node)
{
	// put as parameter
	last_node->args = add_argstoken(last_node->args, token);
	// get next token
	return ;
}

t_tree	*addtoken_to_tree(char **env, char **tokens)
{
	int		controller;
	t_tree	*last_node;
	char	**args;
	char	*token;
	int		tokentype;
	
	tokentype = 0;
	args = NULL;
	controller = 0;
	last_node = NULL;
	while (tokentype != -1)
	{
		//update
		token = token_updater(tokens, env, &controller);
		tokentype = get_token_type(token, env);
		printf("addtoken_to_tree():token:%s-tokentype:%d\n", token, tokentype);
		if (tokentype == HEREDOC)
			addtoken_heredoc(env, token, tokens, &controller, last_node);
		if (tokentype == WORD)
			addtoken_words(token, last_node);
		// make a node
		if (NODE_WORTHY)
			last_node = add_to_tree(tokentype, args, last_node);
		if (tokentype == BUILTIN || tokentype == EXECUTABLE)
			last_node->args = add_argstoken(last_node->args, token);
	}
	return (last_node);
}