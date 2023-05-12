/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_resources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:04:19 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/11 17:19:17 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	free_all_resources(int **pipe_fd)
{
    free(pipe_fd[0]);
    free(pipe_fd[1]);
    free(pipe_fd);
}