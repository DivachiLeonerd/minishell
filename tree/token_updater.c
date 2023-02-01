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

char    *token_updater(char *token, char *new_token, int *index,  t_list *env)
{
    int     i;
    char    *str;
    int     size;

    i = *index;
    size = get_size(&token[i]); //still have to make get_size
    if (size)
    {
        if (ft_chrcmp(token[i], "\'\""))
        {
            str = no_mem(ft_substr(&token[i + 1], 0, size - 2));//still have to make no_mem
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