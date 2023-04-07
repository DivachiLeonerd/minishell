/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:24:02 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/04/05 16:48:56 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../built-ins/built-ins.h"
#include "../libft/libft.h"


static int      nquoted_size(char *s)
{
	int     i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (ft_chrcmp(s[i], "\'") && ft_chrcmp(s[i], "\""))
			j++;
		if (j == 2)
			return (i);
		i++;
	}
	return (i);
}


static int      quoted_size(char *s)
{
	int     i;

	i = 1;
	while (s[i])
	{
		if (s[0] == s[i])
			return (i);
		i++;
	}
	return (0);
}


static int      get_size(char *s)
{
	if (!s)
		return (0);
	if (ft_chrcmp(s[0], "\'\""))
		return (quoted_size(s));
	else
		return (nquoted_size(s));
}


char    *token_updater(char **tokens, char **env, int *var)
{
	int				size;
	char			*str;
	char			*token;
	
	
	token = tokens[*var];
	//get_size() fetches strlen of token inside quotes
	// printf("in token_updater:token:%s\n", token);
	size = get_size(token);
	if (size)
	{
		if (ft_chrcmp('\'', token)
			&& ft_chrcmp('\"', token))
		{
			str = no_mem(ft_substr(token, 1, size - 2));
			if (token[0] == '\"')
				str = str_expander(str, env);
		}
		else
			str = no_mem(ft_substr(token, 0, size));
	}
	else
	{
		free(token);
		return (NULL);
	}
	*var += 1;
	free (token);
	return (str);
}

