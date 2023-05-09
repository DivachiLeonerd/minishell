/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_beta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:15 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/05/09 16:34:14 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "parser.h"

int	syntax_checker(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (line[0] == '>' || line[0] == '<' || line[0] == '|')
		return (1);
	//also, the last character cant be <, > or >>
	while (line[i] && j < 3)
	{
		i++;
		if (line[i] == '>' || line[i] == '<' || line[i] == '|')
			j++;
		else
			j = 0;
		//This is for cases like: "[text] <| [text]", "<|" isn't valid
		if (j == 2 && line[i] != line[i - 1])
			return (2);
	}
	if (line[i] == 0)
		return (0);
	else
		return (1);
	return (0);
}
