/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
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


char    *str_expander(char *s, t_list *env)
{
    char    *token;
    int     size;
    int     i;

    token = NULL;
    i = 0;
    if (!s)
    {
        perror("What a grave mistake in str_expander()");
        exit(69420);
    }
    while (s[i])
    {
        if (s[i] != '$')
        {
            size = word_size(s);
            token = join_tokens(token, );
            i += size;
        }
        else if (s[i] == '$' && s[i + 1] && (s[i + 1] == '?'))
        {
            token = join_tokens(token, ft_itoa(errno), 1);
            i += 1;
        }
        else if (s[i] == '$')
            size += ft_strlen(*(find_env_full_var(s, env)));
    if (s[i] == '$')
	{
        // token = cifrão_expander(s, token, &i, env); maybe? Uma função que o echo possa chamar também?
		i++;
		var_value = find_env_full_var(&(s[i]), envp);
		if (var_value[0] == NULL)
			write(1, "$", 1);
		printf("%s", var_value[0]);
		while (s[i] != ' ' && s[i] != 0)
			i++;
	}
		ft_echo(&(s[i]), env, flag);
    }
    free(s);
    return (token);
}