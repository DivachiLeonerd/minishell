/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/04/23 18:23:27 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../define.h"
# include "../libft/libft.h"

# define LEFT 1
# define RIGHT 2

t_heredoc	*make_heredoc(void);
ssize_t		get_heredoc_input(t_heredoc *heredoc, char *delimiter);
int			token_manager(char *token);
char		*token_updater(char **tokens, char **env, int *i);
int			get_token_type(char *token, char **env);
t_tree		*parser_init(char *s, char ***env);
int			syntax_checker(int tokentype);
t_tree		*addtoken_to_tree(char **env, char **tokens);
void		*no_mem(void *p);
char		*str_expander(char *s, char **env);
#endif
