/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:19:20 by afonso            #+#    #+#             */
/*   Updated: 2023/01/05 15:50:59 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"

int	cd (char *pathname) // depois temos que usar getcwd() para mudar o prompt
{
	return (chdir(pathname));
}