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

int    *token_manager(char *token)
{
    int     i;
    int     dollar_sign;
    int     single_quote;
    int     double_quote;

    if (!token)
        return (0);
    i = 0;
    dollar_sign = 0;
    single_quote = 0;
    double_quote = 0;
    while (token[i])
    {
        if (token[i] == '\'')
            single_quote++;
        else if (token[i] == '\"')
            double_quote++;
        else if (token[i] == '$')
            dollar_sign++;
        i++;
    }
    if (single_quote > 1 || double_quote > 1 || dollar_sign > 0)
        return (1);
    return (0);
}

/*Outra função qualquer que vai chamar a token_manager
char      *do_something_with_the_token(char *token, t_list *env)
{
    int i;
    char    new_token;
    i = 0;
    if (!token_manager)
        return token;
    new_token = NULL;
    while (token[i])
    {
        new_token = token_updater(token, new_token, ?????); //stupid name up for debate
        i++;
    }
    free(token);
    return (new_token)
}
*/
