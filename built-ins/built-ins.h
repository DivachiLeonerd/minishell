/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:18:23 by afonso            #+#    #+#             */
/*   Updated: 2023/03/06 14:54:04 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
#define BUILTINS_H

#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int		ft_echo(char **args);
char	**find_env_full_var(char *var_name, char **envp);
char 	*get_variable_name(char *message);
char	**ft_pwd(char **envp);
int		cd(char *pathname);
int		env(char **envp);
char	**export(char **args, char **envp);
int		get_env_fd(char **envp);
int		how_many_arrays(char **double_ptr);
char	**build_envp(char **envp);
char	**unset(char **args, char **envp);
char	**env_realloc(char **envp, int	numof_new_arrays, char *var);
void	free_env(char **envp);
int		add_var_to_env(char **new_env, char **old_env, char *var);
int		replace_env_var(char **new_env, char **old_env, char *var);
int		delete_var_from_env(char **new_env, char **old_env, char *var);
int		is_builtin(char *command);
int		execute_non_builtin(char *command_name, char **myenvp, char **argv);
int		is_builtin(char *command);

#endif
