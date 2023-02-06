/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:24:02 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/02/02 11:24:04 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


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
