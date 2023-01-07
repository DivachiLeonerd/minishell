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

int     syntax_checker(char *line)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (line[0] == '>' || line[0] == '<' || line[0] == '|')
    {
        printf("linha 23\n");
        return(0);
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
            printf("linha 37\n");
            return (0);
        }
    }
    if (line[i] == NULL)
      printf("no problem bro ;)\n");
    else
    {
        printf("Actually theres a lil problemo bro\n");
        return (1)
    }
    return(0);
}


int main(void)
{
    char *line = "asdf>>ghfd|||";
    syntax_checker(line);
    return(0);
}