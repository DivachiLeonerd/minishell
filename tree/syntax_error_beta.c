/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_beta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:15 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/06/21 13:30:56 by buny             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "parser.h"

int	valid_eol(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		i++;
	if (line[i - 1] == '>' || line[i - 1] == '<' || line[i - 1] == '|')
	{
		printf("Ohh, do you need help honey?\n");
		return (1);
	}
	if (line[i - 1] == ' ')
	{
		i--;
		line[i] = '\0';
		valid_eol(line);
	}
	return (0);
}

int	syntax_checker(char *line, int i, int j)
{
	while (line[i] == ' ')
		i++;
	if (ft_strlen(line) == (size_t)i)
		return (1);
	if (line[0] == '>' || line[0] == '<' || line[0] == '|')
	{
		return (1);
	}
	while (line[i] && j < 3)
	{
		i++;
		if (line[i] == '>' || line[i] == '<' || line[i] == '|')
			j++;
		else
			j = 0;
		if (j == 2 && line[i] != line[i - 1])
			return (2);
	}
	if (valid_eol(line))
		return (1);
	if (line[i] == 0)
		return (0);
	else
		return (1);
	return (0);
}
