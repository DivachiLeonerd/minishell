/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_to_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:47 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/06/02 18:13:12 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../built-ins/builtins.h"
#include "minishell.h"

static void	addtoken_heredoc(char **tokens,
	int *controller, t_tree *last_node)
{
	char	*token;

	token = token_updater(tokens, controller);
	last_node->heredoc = make_heredoc();
	last_node->heredoc->bytes_stored = get_heredoc_input
		(last_node->heredoc, token);
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

static t_tree	*not_word(int tokentype, t_tree *last_node, int *i)
{
	if (tokentype == PIPE)
		*i = 0;
	last_node = add_to_tree(tokentype, last_node);
	return (last_node);
}

static t_tree	*manage_token(int *controller, t_tree *last_node,
		char *token, char **tokens)
{
	static int	i;
	int			tokentype;

	tokentype = get_token_type(token);
	if (((tokentype == BUILTIN || tokentype == EXECUTABLE) && i == 1))
		tokentype = WORD;
	else if (tokentype != WORD)
		last_node = not_word(tokentype, last_node, &i);
	if (tokentype == WORD)
		addtoken_words(token, last_node);
	if (tokentype == HEREDOC)
		addtoken_heredoc(tokens, controller, last_node);
	if ((tokentype == BUILTIN || tokentype == EXECUTABLE) && i == 0)
	{
		i = 1;
		last_node->args = add_argstoken(last_node->args, token);
	}
	if (tokentype == -1)
		i = 0;
	return (last_node);
}

t_tree	*addtoken_to_tree(char **tokens)
{
	int		controller;
	t_tree	*last_node;
	char	*token;

	controller = 0;
	last_node = NULL;
	token = (char *)1;
	while (token != NULL)
	{
		token = token_updater(tokens, &controller);
		last_node = manage_token(&controller, last_node, token, tokens);
		free(token);
	}
	return (last_node);
}
