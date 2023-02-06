/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/02/02 11:22:46 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>


t_tree *parser_init(char *s, t_list *env)
{
    t_tree *tree;
    int what_is_token;
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
        what_is_token = get_token_type(token);
        if (what_is_token == 6) //token isn't <, >, |, >>, <<
            token = do_something_with_the_token(token, env);
        //tree building function
    }
    return tree;
}