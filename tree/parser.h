#ifndef PARSER_H
# define PARSER_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../define.h"
#include "../libft/libft.h"


#define LEFT 1
#define RIGHT 2

t_tree *node_creator(int id);
void    create_top_node(t_tree **tree, t_tree *node);
void    create_left_node(t_tree *previous, t_tree *new_node);
void    create_right_node(t_tree *previous, t_tree *node);
t_tree	*pipes_cond(int tokentype, t_tree *aux, t_tree *node);
t_tree	*redir_cond(t_tree *aux, t_tree *node);
t_tree	*heredoc_cond(int tokentype, t_tree *aux, t_tree *node);
t_heredoc *make_heredoc(void);
void	get_heredoc_input(t_heredoc *heredoc);
void	close_heredocs(t_heredoc **all_heredocs);
#endif

