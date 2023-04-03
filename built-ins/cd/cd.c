/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:19:20 by afonso            #+#    #+#             */
/*   Updated: 2023/04/03 16:02:32 by atereso-         ###   ########.fr       */
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
	printf("IN CD()\nmyenvp:%p\n",envp);
	if (!old_pwd)
	{
		free(old_pwd);
		return (envp);
	}
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
		printf("IN CD()\nmyenvp:%p\n",envp);
		envp = export(&temp, envp);
		free(temp);
	}
	else
		free(old_pwd);
	printf("IN CD()\nmy new_envp:%p\n",envp);
	return (envp);
}