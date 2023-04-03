/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:46:35 by afonso            #+#    #+#             */
/*   Updated: 2023/04/03 15:44:11 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPING_H
#define PIPING_H

#include "../define.h"
#include "../libft/libft.h"
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>


int		return_righttokenid(t_tree *command_node);
t_tree	*find_first_command(t_tree *bintree);
void	execute_builtin(char *command, char **myenvp, char **args);
int		is_builtin(char *command);
void	make_and_run_pipes(t_tree *bintree, char **myenvp);
int		**pipe_creation(int how_many_pipes);
int		output_redirection(int fd1, t_tree *node, int tokentype);
int		piping(int *pid, int **pipe_fd, int num_of_pipes, int index);
t_tree	*find_command_node(int index, t_tree *bintree);
void	initialize_forking_processes(int *pid, int numof_processes);
int		how_many_pipes(t_tree *bintree);
char	**run_pipes(int numof_pipes, t_tree *bintree, int *pid, char ***myenvp);
t_tree	*find_first_command(t_tree *bintree);
char	**make_pipes(t_tree *bintree, char **myenvp);
#endif