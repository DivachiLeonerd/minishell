/*************************************************************************/
/*                                                                       */
/*                                                                       */
/*     HEADER FUCKING FILE FUCK YEAH MOTHERFUCKER                        */
/*                                                                       */
/*     Created: 69/420 who:fucking:cares by: me                          */
/*     Updated: 69/421 who:fucking:cares by: me                          */
/*                                                             42        */
/*************************************************************************/

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

