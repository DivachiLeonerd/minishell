/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:18:23 by afonso            #+#    #+#             */
/*   Updated: 2022/12/22 16:32:30 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int		ft_echo(char *message, char **envp);
char	**find_env_full_var(char *var_name, char **envp);
char 	*get_variable_name(char *message);
int		ft_pwd(char **argv, char **envp);
int		cd(char *pathname);
int		env(char **envp);
char	**export(char *variable, char **envp);
int		get_env_fd(char **envp);
int		how_many_arrays(char **double_ptr);
char	**build_envp(char **envp);
char	**unset(char *variable, char **envp);
char	**env_realloc(char **envp, int	numof_new_arrays, char *var);
void	free_env(char **envp);
int		add_var_to_env(char **new_env, char **old_env, char *var);
int		replace_env_var(char **new_env, char **old_env, char *var);
int		delete_var_from_env(char **new_env, char **old_env, char *var);