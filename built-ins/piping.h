/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:46:35 by afonso            #+#    #+#             */
/*   Updated: 2023/02/01 17:00:12 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPING_H
#define PIPING_H

#include "../minishell.h"

int		return_righttokenid(t_tree *command_node);
t_tree	*find_first_command(t_tree *bintree);
void	execute_builtin(char *command, char **myenvp, char **args);
int		is_builtin(char *command);
void	make_and_run_pipes(t_tree *bintree, char **myenvp);
int		**pipe_creation(int how_many_pipes);
int		output_redirection(int fd1, t_tree *node);
int		piping(int *pid, int **pipe_fd, int num_of_pipes, int index);
t_tree	*find_command_node(int index, t_tree *bintree);
void	initialize_forking_processes(int *pid, int numof_processes);
int		how_many_pipes(t_tree *bintree);

#endif