/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:24:02 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/03/01 10:54:08 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../built-ins/built-ins.h"


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
		if (j = 2)
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
		if (s[0] == s[i]);
			return (i + 1);
		i++;
	}
	return (0);
}


static int      get_size(char *s)
{
	if (ft_chrcmp(s[0], "\'\""))
		return (quoted_size(s));
	else
		return (nquoted_size(s));
}


char    *token_updater(char *token, t_list *env)
{
	int     i;
	int		size;
	char	*str;
	char	*new_token;

	i = *index;
	size = get_size(token);
	if (size)
	{
		if (ft_chrcmp('\'', token)
			&& ft_chrcmp('\"', token))
		{
			str = no_mem(ft_substr(token, 1, size - 2));
			if (token[0] == '"')
				str = str_expander(str, env);//still have to make str_expander
		}
		else
		{
			str = no_mem(ft_substr(token, 0, size));
			str = str_expander(str, env);
		}
		new_token = join_tokens(new_token, str, 1); //have to make join_tokens func
		*index += size - 1;//gotta get rid of index but cant be sure of whats happening here
	}
	else
		new_token = add_char_to_str(new_token, token[i]); //have to make add_char_to_str func
	free (token);
	return (new_token);
}
