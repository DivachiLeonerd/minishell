/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:46:35 by afonso            #+#    #+#             */
/*   Updated: 2023/04/23 16:53:36 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPING_H
# define PIPING_H

# include "../define.h"
# include "../libft/libft.h"
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>

void	execute_builtin(char *command, char **myenvp, char **args);
int		is_builtin(char *command);
int		output_redirection(int fd1, t_tree *node, int tokentype);
void	forking_processes(int *pid, int numof_processes);
int		how_many_pipes(t_tree *monotree);
char	**run_pipes(int numof_pipes, t_tree *monotree, int *pid, char ***myenvp);
#endif