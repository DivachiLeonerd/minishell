/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:59 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/03/30 15:30:06 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parser.h"
#include "../built-ins/built-ins.h"
#include "../define.h"

int get_token_type(char *token, char **myenvp)
{
    int         token_size;
    char        *aux;
    static int  last_tokentype;

    aux = NULL;
    if (!token)
    {
        last_tokentype = 0;
        return (-1);
    }
    if (token[0] == '\0')
        return (-1);
    token_size = ft_smol_strlen(token);
    if (token_size == 1)
    {
        if (token[0] == '>')
            return (O_REDIR);
        else if (token[0] == '<')
            return (I_REDIR);
        else if (token[0] == '|')
            return (PIPE);
    }
    else if (token_size == 2)
    {
        if (token[0] == '>' && token[1] == '>')
            return (APPEND);
        else if (token[0] == '<' && token[1] == '<')
            return (HEREDOC);
    }
    if (is_builtin(token))
    {
        last_tokentype = BUILTIN;
        return (BUILTIN);
    }
    if (last_tokentype != BUILTIN)
        aux = find_command_path(myenvp, token);
    if (aux)
    {
        free(aux);
        return (EXECUTABLE);
    }
    return (WORD);
}

void    *no_mem(void *p)
{
    if (!p)
    {
        ft_putendl_fd("No more available memory for minishell!", 2);
        chad_exitstatus = EXIT_FAILURE;
        return (NULL);
    }
    return (p);
}

