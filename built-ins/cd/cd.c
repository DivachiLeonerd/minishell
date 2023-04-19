/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:19:20 by afonso            #+#    #+#             */
/*   Updated: 2023/04/19 23:02:52 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"
#include "../../tree/parser.h"

char	**cd (char *pathname, char **envp) // depois temos que usar getcwd() para mudar o prompt
{
	int	ret;
	char	*old_pwd;
	char	*pwd;
	char	*temp;
	char	*aux;
	
	ret = 1;
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
	{
		free(old_pwd);
		return (envp);
	}
	if (!pathname)
	{
		pathname = ft_strdup("$HOME");
		pathname = str_expander(pathname, envp);
	/* 	if (pathname[0] == '~')
		{
			ft_strjoin(pathname, "")
		} */
		ret = chdir(pathname);
		free(pathname);
	}
	else if (pathname[0] == '~')
	{
		temp = ft_strdup("$HOME");
		temp = str_expander(temp, envp);
		aux = ft_strdup(pathname);
		pwd = ft_substr(aux, 1, ft_strlen(aux) - 1);
		free(aux);
		aux = ft_strjoin(temp, pwd);
		free(temp);
		ret = chdir(aux);
		free(aux);
		free(pwd);
	}
	else
		ret = chdir(pathname);
	if (!ret)
	{
		temp = ft_strjoin("OLDPWD=", old_pwd);
		free(old_pwd);
		envp = export(&temp, envp);
		free(temp);
		pwd = getcwd(NULL, 0);
		temp = ft_strjoin("PWD=", pwd);
		free(pwd);
		envp = export(&temp, envp);
		free(temp);
	}
	else
		free(old_pwd);
	return (envp);
}