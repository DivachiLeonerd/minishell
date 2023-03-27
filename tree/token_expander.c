/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:59 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/02/02 11:23:02 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parser.h"
#include "../built-ins/built-ins.h"

static int      word_size(char *s)
{
	int     i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return i;
		i++;
	}
	return i;
}


char *join_tokens(char *s1, char *s2, int i)
{
	char    *new;

	new = NULL;
	if (s1 && s2)
		new = no_mem(ft_strjoin(s1, s2));
	free(s1);
	if (i)
		free(s2);
	return (new);
}

//expands string wrapped in double quotes and with a '$'
char	*str_expander(char *s, char **env)
{
	char	*token;
	size_t	size;
	int		i;
	char	*temp;
	char	**full_name;

	token = NULL;
	temp = NULL;
	i = 0;
	if (!s)
	{
		perror("What a grave mistake in str_expander()");
		chad_exitstatus = 69420;
		return (NULL);
	}
	if (ft_strlen(s) == 1 && s[0] == '$')
		return (s);
	i = word_size(s);
	if (s[i] == '$')
	{
		token = ft_substr(token,0, i);//token ="ola"
		size = ft_strlen(&(s[i]));//strlen do "PWD"
		temp = ft_substr(s, i, size);//token = "PWD"
		full_name = find_env_full_var(temp, env);//full_name = "PWD=./"
		free(temp);
		if (!full_name)
			return (token);
		temp = ft_substr(*full_name, size, ft_strlen(*full_name) - size - 1);
		token = ft_strjoin(token, temp);
		free(temp);
		return (token);
	}
	return (s);
}