#include "parser.h"

int get_token_type(char *token)
{
    int token_size;
    int token_id;

    token_size = (int)ft_strlen(token);
    if (!token)
        return (0);
    if (token_size ==1)
    {
        if (token[0] == '>')
        {
            return (1);
        }
        
    }
}