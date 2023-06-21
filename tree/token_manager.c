/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_manager.c                                    :+:      :+:    :+:   */
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
