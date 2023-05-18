/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:23:07 by afonso            #+#    #+#             */
/*   Updated: 2023/05/18 17:41:27 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"
#include "../../minishell.h"

int	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	return (errno);
}
