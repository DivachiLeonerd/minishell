/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:19:20 by afonso            #+#    #+#             */
/*   Updated: 2023/06/02 18:07:25 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"
#include "../../tree/parser.h"
#include "../../minishell.h"

int	no_pathname(char *pathname, char *old_pwd)
{
	pathname = ft_strdup("$HOME");
	pathname = str_expander(pathname);
	chdir(pathname);
	if (errno != 0)
	{
		free(old_pwd);
		return (errno);
	}
	free(pathname);
	return (errno);
}

int	pathname_starts_with_til(char *pathname, char *pwd, char *temp, char *aux)
{
	int	ret;

	ret = 0;
	temp = ft_strdup("$HOME");
	temp = str_expander(temp);
	aux = ft_strdup(pathname);
	pwd = ft_substr(aux, 1, ft_strlen(aux) - 1);
	free(aux);
	aux = ft_strjoin(temp, pwd);
	free(temp);
	errno = 0;
	ret = chdir(pathname);
	if (errno != 0)
		g_struct.chad_exitstatus = errno;
	free(aux);
	free(pwd);
	return (ret);
}

int	ret_is_zero(char *old_pwd, char *temp, char *pwd)
{
	temp = ft_strjoin("OLDPWD=", old_pwd);
	free(old_pwd);
	export(&temp);
	free(temp);
	pwd = getcwd(NULL, 0);
	temp = ft_strjoin("PWD=", pwd);
	free(pwd);
	export(&temp);
	free(temp);
	if (errno != 0)
		return (errno);
	return (0);
}

int	cd(char *pathname, char *pwd, char *temp, char *aux)
{
	int		ret;
	char	*old_pwd;

	errno = 0;
	ret = 0;
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
	{
		free(old_pwd);
		return (errno);
	}
	if (!pathname)
		no_pathname(pathname, old_pwd);
	else if (pathname[0] == '~')
		pathname_starts_with_til(pathname, pwd, temp, aux);
	else
		ret = chdir(pathname);
	if (ret == 0)
		ret_is_zero(old_pwd, temp, pwd);
	else
		free(old_pwd);
	return (errno);
}
