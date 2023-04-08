/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:47 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/04/08 16:17:43 by atereso-         ###   ########.fr       */
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

t_tree	*addtoken_to_tree(char *token, int tokentype, char **env, char **tokens, t_tree **last_node, int *controller)
{
	char			*new_token;
	char			**args; //dinamicamente mallocado
	int				i;
	int				temp_tokentype;

	i = 0;
	temp_tokentype = 0;
	args = NULL;
	new_token = NULL;
	if (tokentype == HEREDOC)
	{
		free(token);
		token = NULL;
		free((*last_node)->args);
		(*last_node)->args = NULL;
		new_token = token_updater(tokens, env, controller);
		// printf("in addtoken_to_tree():heredoc:%s\n", token);
		(*last_node)->heredoc = make_heredoc();
		(*last_node)->heredoc->bytes_stored = get_heredoc_input((*last_node)->heredoc, new_token);
		free(new_token);
		// printf("in addtoken_to_tree():heredoc bytes stored:%ld\n", (*last_node)->heredoc->bytes_stored);
		return ((*last_node));
	}
	if (tokentype != WORD && tokentype != HEREDOC  && tokentype > 0)
	{
		(*last_node) = add_to_tree(tokentype, args, (*last_node));
		if (tokentype == BUILTIN || tokentype == EXECUTABLE)
		{
			new_token = ft_strdup(token);
			// printf("in addargstoken():new_token:%s\n", new_token);
			(*last_node)->args = add_argstoken((*last_node)->args, new_token);
		}
		new_token = token_updater(tokens, env, controller);
		// printf("in addtoken_to_tree():new_token:%s\n", new_token);
		temp_tokentype = get_token_type(new_token, env);
		// printf("in the same func:tokentype:%d\n", temp_tokentype);
		if (temp_tokentype == HEREDOC || temp_tokentype == PIPE || temp_tokentype == BUILTIN || temp_tokentype == EXECUTABLE)
			return (addtoken_to_tree(new_token, temp_tokentype,env, tokens, last_node, controller));
		while (temp_tokentype == WORD)
		{
			if (i == 0)
				(*last_node)->args = add_argstoken((*last_node)->args, new_token);
			new_token = token_updater(tokens, env, controller);
			temp_tokentype = get_token_type(new_token, env);
			if (temp_tokentype != WORD)
			{
				free(token);
				token = NULL;
				return (addtoken_to_tree(new_token, temp_tokentype, env, tokens, last_node, controller));
			}
			(*last_node)->args = add_argstoken((*last_node)->args, new_token);
			i++;
		}
		(*last_node) = add_to_tree(temp_tokentype, args, (*last_node));
	}
	if (token)
		free(token);
	return ((*last_node));
}