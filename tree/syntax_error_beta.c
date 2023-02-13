/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_beta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuny-fe <jbuny-fe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:15 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/02/02 11:23:17 by jbuny-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
