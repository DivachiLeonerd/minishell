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
        token = token_getter();//future get_token func
        if (!token)
            break;
        if ()//token der erro
        {
            //free token
            return (NULL);
        }
        what_is_token = get_token_type(token); //figure out what the token is
        if (what_is_token == word)
            token = //func to handle token if it is a werd
        //tree building function
    }
    return tree
}