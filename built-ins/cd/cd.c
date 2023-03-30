/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:19:20 by afonso            #+#    #+#             */
/*   Updated: 2023/03/30 17:21:53 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

int	cd (char *pathname, char **envp) // depois temos que usar getcwd() para mudar o prompt
{
	int	ret;
	char	*old_pwd;
	char	*pwd;
	char	*temp;
	
	old_pwd = getcwd(NULL, 0);
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
	}
	return (ret);
}