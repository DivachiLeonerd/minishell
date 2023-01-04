/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:25:59 by afonso            #+#    #+#             */
/*   Updated: 2023/01/03 14:18:19 by afonso           ###   ########.fr       */
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
	char	*value;

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

int	ft_echo(char *message, char **envp, int flag)// falta implementar a flag -n mas preciso de esclarecimentos
{
	int i;
	char **var_value;

	i = 0;
	if (!message || message[i] == 0)
	{
		IF_FLAG_ACTIVE// doesn't work with normal shell but will work on our own
		return (0);
	}
	while (message[i] != '$' && message[i])
	{
		printf("%c", (message[i]));
		i++;
	}
	if (message[i] == '$')
	{
		i++;
		var_value = find_env_full_var(&(message[i]), envp);
		if (var_value[0] == NULL)
			write(1, "$", 1);
		printf("%s", var_value[0]);
		while (message[i] != ' ' && message[i] != 0)
			i++;
	}
		ft_echo(&(message[i]), envp, flag);
	return (0);
}