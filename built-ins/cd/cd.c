/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:19:20 by afonso            #+#    #+#             */
/*   Updated: 2023/04/19 18:28:27 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

char	**cd (char *pathname, char **envp) // depois temos que usar getcwd() para mudar o prompt
{
	int	ret;
	char	*old_pwd;
	char	*pwd;
	char	*temp;
	
	ret = 1;
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
	{
		free(old_pwd);
		return (envp);
	}
	if (!pathname)
		ret = chdir("/home");
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