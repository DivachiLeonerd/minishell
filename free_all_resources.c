/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_resources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:04:19 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/09 16:03:09 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	free_all_resources(char **myenvp, t_tree *bintree, int **pipe_fd)
{
    free(pipe_fd[0]);
    free(pipe_fd[1]);
    free(pipe_fd);
    free_tree(bintree);
    free_matrix(myenvp);
}