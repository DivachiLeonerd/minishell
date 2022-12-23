/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:23:07 by afonso            #+#    #+#             */
/*   Updated: 2022/12/19 11:43:52 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

int	ft_pwd(char **argv, char **envp)
{
	char	*pwd;
	char	*str;


	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	str = ft_strjoin("PWD=", pwd);
	free(pwd);
	export(str, envp);
	free(str);
	return (0);
}