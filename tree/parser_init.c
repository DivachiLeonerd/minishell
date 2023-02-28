/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/02/27 19:46:54 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>


t_tree *parser_init(char *s, t_list *env)
{
    t_tree *bintree;
    int tokentype;
    char *token;

    token = NULL;
    while (1)
    {
        token = token_getter(s);
        if (!token)
            break;
        if (syntax_checker(token) != 0)
        {
            free(token);
            return (NULL);
        }
        tokentype = get_token_type(token);
        if (tokentype == 6) //token isn't <, >, |, >>, <<
            token = do_something_with_the_token(token, env);
        while (tokentype != -1)
            bintree = add_to_tree(tokentype, args);
    }
    return tree;
}