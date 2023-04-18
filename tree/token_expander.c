/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:59 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/04/18 23:15:58 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../built-ins/built-ins.h"
#include "../define.h"

char	*join_tokens(char *s1, char *s2, int i)
{
	char	*new;

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
	size_t	size;
	char	*temp;
	char	**full_name;
	int		i;

	i = 0;
	temp = NULL;
	if (!s)
	{
		perror("What a grave mistake in str_expander()");
		chad_exitstatus = 69420;
		return (NULL);
	}
	if (ft_strlen(s) == 1 && s[0] == '$')
		return (s);
	size = ft_strlen(s);
	if (s[0] == '\"')
		i++;
	if (s[i] == '$')
	{
		temp = ft_substr(s, i, size);//token = "PWD"
		full_name = find_env_full_var(temp, env);//full_name = "PWD=./"
		//printf("%p\n", *full_name);
		free(temp);
		if (!full_name)
			return (NULL);
		temp = ft_substr(*full_name, size, ft_strlen(*full_name) - size);
		free(s);
		printf("str_expander():%s\n", temp);
		return (temp);
	}
	return (s);
}
