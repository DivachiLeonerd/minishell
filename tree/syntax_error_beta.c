/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_beta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:15 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/04/23 19:16:32 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "parser.h"

//WELCOME TO THE DEBBUGERS NIGHTMARE
int	syntax_error(int last_tokentype)
{
	if (last_tokentype == I_REDIR)
		perror("inPUTA ma pilinha");
	else if (last_tokentype == O_REDIR)
		perror("outPUTA ma pilinha");
	else if (last_tokentype == PIPE)
		perror("pipe? pipe ma pilinha");
	else if (last_tokentype == HEREDOC)
		perror("here ma pilinha");
	else if (last_tokentype == APPEND)
		perror("append ma pilinha");
	else
		return (0);
	return (1);
}

static int	check_endof_line(int last_tokentype, int tokentype)
{
	if (tokentype == -1)
	{
		if (last_tokentype == PIPE)
			return (PIPE);
		if (last_tokentype == I_REDIR)
			return (I_REDIR);
		if (last_tokentype == O_REDIR)
			return (O_REDIR);
		if (last_tokentype == APPEND)
			return (APPEND);
		if (last_tokentype == HEREDOC)
			return (HEREDOC);
	}
	return (0);
}

static int	check_repeated_special_token(int last_tokentype, int tokentype)
{
	static int	special_redirect_count;

	if (last_tokentype == tokentype)
	{
		special_redirect_count += 1;
		if (special_redirect_count == 2)
			return (tokentype);
	}
	else
		special_redirect_count = 0;
	return (0);
}

int	syntax_checker(int tokentype)
{
	static int	last_tokentype;
	int			i;

	i = 1;
	//beginning of line
	if (last_tokentype == 0 && tokentype == PIPE)
		return (PIPE);
	//end of line
	if (check_endof_line(last_tokentype, tokentype))
		return (tokentype);
	//no more than 1 pipe
	if (last_tokentype == PIPE && tokentype == PIPE)
		return (PIPE);
	// cant have two different special tokens next to eachother
	//no no, don't type that there, that is, my no no rule
	while (i <= 5 && check_repeated_special_token(last_tokentype, i++))
		return (last_tokentype);
	last_tokentype = tokentype;
	return (0);
}

/* Commands are composed of words and operators separated by whitespace.
Each command may be followed by zero or more command arguments, which are also separated by whitespace.
Words and operators may be separated by whitespace, but quotes and backslashes can be used to preserve whitespace.
Quoted strings can include any character except newline, and backslashes can be used to escape special characters.
Command substitution allows the output of a command to be used as an argument to another command.
Redirection allows the input or output of a command to be redirected to a file or another command.
Pipes allow the output of one command to be sent as input to another command.
Conditional statements, loops, and functions are also part of the Bash grammar, with their own syntax rules.
 */