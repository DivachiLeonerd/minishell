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