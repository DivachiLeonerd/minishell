/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:28:54 by afonso            #+#    #+#             */
/*   Updated: 2023/06/02 18:17:23 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdlib.h>

typedef struct s_heredoc
{
	int				pipe_fd[2];
	char			*delimiter;
	ssize_t			bytes_stored;
}t_heredoc;

typedef struct s_tree
{
	int				tokentype;
	char			**args;
	t_heredoc		*heredoc;
	struct s_tree	*left_branch;
	struct s_tree	*right_branch;
	struct s_tree	*back;
}t_tree;

# define I_REDIR 1
# define O_REDIR 2
# define PIPE 3
# define HEREDOC 4
# define APPEND 5
# define BUILTIN 6
# define EXECUTABLE 7
# define WORD 8
# define PROMPT "\033[1;32mPequenaConcha:\033[1;34m"

void	free_matrix(char **envp);
char	*find_command_path(char *command);
#endif