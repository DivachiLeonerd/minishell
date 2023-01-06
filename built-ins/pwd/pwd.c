/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:23:07 by afonso            #+#    #+#             */
/*   Updated: 2023/01/05 15:51:30 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

char	**ft_pwd(char **myenvp)
{
	char	*pwd;
	char	*str;


	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	str = ft_strjoin("PWD=", pwd);
	free(pwd);
	myenvp = export(str, myenvp);
	free(str);
	return (myenvp);
}