/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:59 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/05/18 18:10:39 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../built-ins/builtins.h"
#include "../define.h"
#include "../minishell.h"

static int	get_operator(int token_size, char *token)
{
	if (token_size == 1)
	{
		if (token[0] == '>')
			return (O_REDIR);
		else if (token[0] == '<')
			return (I_REDIR);
		else if (token[0] == '|')
			return (PIPE);
	}
	else if (token_size == 2)
	{
		if (token[0] == '>' && token[1] == '>')
			return (APPEND);
		else if (token[0] == '<' && token[1] == '<')
			return (HEREDOC);
	}
	return (0);
}

int	get_token_type(char *token)
{
	int		token_size;
	char	*aux;
	int		is_operator;

	aux = NULL;
	if (!token)
		return (-1);
	if (token[0] == '\0')
		return (-1);
	token_size = ft_smol_strlen(token);
	is_operator = get_operator(token_size, token);
	if (is_operator)
		return (is_operator);
	if (is_builtin(token))
		return (BUILTIN);
	else
		aux = find_command_path(token);
	if (aux)
	{
		free(aux);
		return (EXECUTABLE);
	}
	return (WORD);
}

void	*no_mem(void *p)
{
	if (!p)
	{
		g_struct.chad_exitstatus = 12;
		return (NULL);
	}
	return (p);
}
