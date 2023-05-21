

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:47 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/05/21 22:28:29 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../built-ins/built-ins.h"
#include "minishell.h"
int	token_manager(char *token)
{
	int		i;
	int		dollar_sign;
	int		single_quote;
	int		double_quote;

	if (!token)
		return (1);
	i = 0;
	dollar_sign = 0;
	single_quote = 0;
	double_quote = 0;
	while (token[++i])
	{
		single_quote += token[i] == '\'';
		double_quote += token[i] == '\"';
		dollar_sign += token[i] == '$';
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
	int		i;

	i = 0;
	size = how_many_arrays(args);
	new_args = malloc((size + 2) * sizeof(char *));
	while (args && i < size)
	{
		new_args[i] = ft_strdup(args[i]);
		i++;
	}
	new_args[i] = ft_strdup(token);
	new_args[++i] = NULL;
	if (size)
		free_matrix(args);
	return (new_args);
}

static void	addtoken_heredoc(char **tokens,
	int *controller, t_tree *last_node)
{
	char	*token;

	token = token_updater(tokens, controller);
	last_node->heredoc = make_heredoc();
	last_node->heredoc->bytes_stored = get_heredoc_input(last_node->heredoc, token);
	free(token);
	return ;
}

static void	addtoken_words(char *token, t_tree *last_node)
{
	if (!last_node)
	{
		g_struct.chad_exitstatus = 127;
		return ;
	}
	last_node->args = add_argstoken(last_node->args, token);
	return ;
}

t_tree	*addtoken_to_tree(char **tokens)
{
	int		i;
	int		controller;
	t_tree	*last_node;
	char	*token;
	int		tokentype;

	i = 0;
	tokentype = 0;
	controller = 0;
	last_node = NULL;
	while (tokentype != -1)
	{
		token = token_updater(tokens, &controller);
		tokentype = get_token_type(token);
		if (((tokentype == BUILTIN || tokentype == EXECUTABLE) && i == 1))
			tokentype = WORD;
		else if (NODE_WORTHY)
		{
			if (tokentype == PIPE)
				i = 0;
			last_node = add_to_tree(tokentype, last_node);
		}
		if (tokentype == WORD)
			addtoken_words(token, last_node);
		if (tokentype == HEREDOC)
			addtoken_heredoc(tokens, &controller, last_node);
		if ((tokentype == BUILTIN || tokentype == EXECUTABLE) && i == 0)
		{
			i = 1;
			last_node->args = add_argstoken(last_node->args, token);
		}
		free(token);
	}
	printf("nodetype:%d\n", tokentype);
	return (last_node);
}
