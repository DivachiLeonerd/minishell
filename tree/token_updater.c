/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:24:02 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/02/16 11:24:13 by afonso           ###   ########.fr       */
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


char    *str_expander(char *s, char **env)
{
    char    **var_value;
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
        // else if (s[i] == '$')
        //     size += ft_strlen(*(find_env_full_var(s, env)));
        if (s[i] == '$')
        {
            i++;
            var_value = find_env_full_var(&(s[i]), env);
            size += ft_strlen(var_value[0]);
            if (var_value[0] == NULL)
                return (0);
            else
                printf("%s", var_value[0]);
        }
    }
    free(s);
    return (token);
}

static int      nquoted_size(char *s)
{
    int     i;

    i = 0;
    while (s[i])
    {
        if (ft_chrcmp(s[i], "\'\""))
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


char    *token_updater(char *token, char *new_token, int *index,  t_list *env)
{
    int     i;
    char    *str;
    int     size;

    i = *index;
    size = get_size(&token[i]);
    if (size)
    {
        if (ft_chrcmp(token[i], "\'\""))
        {
            str = no_mem(ft_substr(&token[i + 1], 0, size - 2));
            if (token[i] == '"')
                str = str_expander(str, env);//still have to make str_expander
        }
        else
        {
            str = no_mem(ft_substr(&token[i], 0, size));
            str = str_expander(str, env);
        }
        new_token = join_tokens(new_token, str, 1); //have to make join_tokens func
        *index += size -1;
    }
    else
        new_token = add_char_to_str(new_token, token[i]); //have to make add_char_to_str func
    return (new_token);
}
