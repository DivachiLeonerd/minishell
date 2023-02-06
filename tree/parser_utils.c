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


int get_token_type(char *token)
{
    int token_size;
    int token_id;

    token_size = (int)ft_strlen(token);
    if (!token)
        return (0);
    if (token_size == 1)
    {
        if (token[0] == '>')
            return (1);
        else if (token[0] == '<')
            return (2);
        else if (token[0] == '|')
            return (3);
    }
    else if (token_size == 2)
    {
        if (token[0] == '>' && token[1] == '>')
            return (4);
        else if (token[0] == '<' && token[1] == '<')
            return (5);
    }
    else
        return (6); //token in neither redir nor pipe
}


void    *no_mem(void *p)
{
    if (!p)
    {
        ft_putendl_fd("No more available memory for minishell!", 2);
        exit(EXIT_FAILURE);
    }
}

