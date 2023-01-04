/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:23:07 by afonso            #+#    #+#             */
/*   Updated: 2023/01/03 15:04:59 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

int	ft_pwd(char **argv, char **myenvp)
{
	char	*pwd;
	char	*str;


	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	str = ft_strjoin("PWD=", pwd);
	free(pwd);
	myenvp = export(str, myenvp);
	free(str);//se calhar e isto
	return (0);
}