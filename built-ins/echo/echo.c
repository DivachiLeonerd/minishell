/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:25:59 by afonso            #+#    #+#             */
/*   Updated: 2023/01/28 17:23:24 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"


//echo tem que poder usar a flag "-n" que faz com que echo
//não printe \n no final da string escrita
//echo tem de conseguir printar com quotes e single quotes
//e saber printar env vars se tiverem '$' e todos os ficheiros se tiver '*'.

char *get_variable_name(char *message)
{
	//message: MYVAR=NAME
	int		i;
	char	*var_name;

	i = 0;
	if (!message || message[i] == 0)
		return (NULL);
	while (message[i] != '=' && message[i] != '\0')
		i++;
	var_name = malloc((i + 1) * sizeof(char));
	var_name[i] = 0;
	ft_strlcpy(var_name, &(message[0]), i + 1);
	return (var_name);
}

char **find_env_full_var(char *message, char **envp)
{
	//message: MYVAR=value

	char	*var_name;
	int		i;

	i = 0;
	var_name = get_variable_name(message);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var_name, ft_strlen(var_name)) == 0)
			break ;
		i++;
	}
	if (envp[i] == NULL)
	{
		free(var_name);
		return ((char **)0);
	}
	free(var_name);
	return (&(envp[i]));
}

int	ft_echo(char **args, char **envp)
{
	int i;
	static int	j;
	char **var_value;
	int	numberof_args;

	numberof_args = how_many_arrays(args);
	i = numberof_args - 1;
	if (numberof_args > 3 || numberof_args < 1)
	{
		printf("\n");
		return (-1);
	}
	if (numberof_args == 1)
	{
		printf("\n");
		return (0);
	}
	if (numberof_args == 2)
	{
		if (ft_strncmp(args[1], "-n", ft_strlen(args[1])) == 0)
			return (0);
	}
	while (args[i][j] && args[i][j] != '$')
		printf("%c", args[i][j++]);
	if (args[i][j] == '$')
	{
		j++;
		var_value = find_env_full_var(&(args[i][j]), envp);
		if (var_value[0] == NULL)
			write(1, "$", 1);
		printf("%s", var_value[0]);
		while (args[i][j] != ' ' && args[i][j] != 0)
			j++;
	}
	if (args[i][j])
		ft_echo(&(args[i]), envp);
	if (ft_strncmp(args[1], "-n", ft_strlen(args[1])) != 0)
		printf("\n");
	return (0);
}