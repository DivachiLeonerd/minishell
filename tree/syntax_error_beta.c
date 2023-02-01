/*************************************************************************/
/*                                                                       */
/*                                                                       */
/*     HEADER FUCKING FILE FUCK YEAH MOTHERFUCKER                        */
/*                                                                       */
/*     Created: 69/420 who:fucking:cares by: me                          */
/*     Updated: 69/421 who:fucking:cares by: me                          */
/*                                                             42        */
/*************************************************************************/

#include <string.h>
#include <stdio.h>
#include "parser.h"

int     syntax_checker(char *line)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (line[0] == '>' || line[0] == '<' || line[0] == '|')
    {
        return(1);
    }
    while(line[i] && j < 3)
    {
        i++;
        if (line[i] == '>' || line[i] == '<' || line[i] == '|')
            j++;
        else
        {
            j = 0;
        }
        if (j == 2 && line[i] != line[i -1])
        {
            return (2);
        }
    }
    if (line[i] == NULL)
      return (0);
    else
        return (1);
    return(0);
}