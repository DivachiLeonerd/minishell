/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:26 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/02/02 11:23:34 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parser.h"

char    *deal_with_operators(char *s, int *i)
{
    char *token;
    int s_size;

    if (!s || !i)
        return (0);
    s_sizaroo = (int)ft_strlen(s);
    

}

char *token_getter(char *s)
{
    static int      i = 0;
    int             j = 0;
    char            *token;

    while (s[i])
    {
        j = 0;
        if (s[i] == '>' || s[i] == '<' || s[i] == '|')
            token = deal_with_operators(s, &i);
        else if (s[i] == ' ')
            token = get_word(s, &i);
        if (token)
            return (token);
        i++;            
    }
    i = 0;
    return (token);
}
