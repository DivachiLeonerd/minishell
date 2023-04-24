/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:47:06 by afonso            #+#    #+#             */
/*   Updated: 2023/04/22 17:52:54 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	ft_child(t_tree *monotree, char **myenvp)
{
	//dup2 stdout to pipe[1]
	//close all other fd's
	//if (redirectio)
	//if (pipe)
	//in both cases gotta dup2
}

int	how_many_pipes(t_tree *monotree)
{
	int		numof_pipes;
	t_tree	*node;

	numof_pipes = 0;
	node = monotree;
	while (node->left_branch != NULL)
	{
		if (node->tokentype == PIPE)
			numof_pipes++;
		node = node->left_branch;
	}
	return (numof_pipes);
}

static void	free_utils(int **pipe_fd, int numof_pipes)
{
	int	i;

	i = numof_pipes - 1;
	while (pipe_fd && i >= 0)
	{
		close(pipe_fd[i][0]);
		free(pipe_fd[i]);
		i--;
	}
	free(pipe_fd);
	return ;
}

//echo ola | grep ola
//echo ola < file1
//echo << ola

/*
1- receive monotree
2-should receive in a command node
3- read tree until u meet a pipe
4-if pipe, fork().
5-dup pipe.
6-function calls itself with a new monotree starting point
*/
void	forking_processes(t_tree *monotree, char **myenvp, int numof_processes, int main_stdin)
{
	int		pipe_fd[2];
	int		pid;

	//fork tem acesso a: tree, pipe_fd
	pipe(pipe_fd);
	if (numof_processes != 0)
	{
		pid = fork();
		numof_processes -= 1;
	}
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		ft_child(monotree, myenvp);
		//dup2 o q precisar e fechar o resto
		exit(EXIT_SUCCESS);
	}
	else
		ft_rapist();
		//dup2 o q precisar e fechar o resto
	return ;
}


//do 1º para o ultimo mas o ultimo tem que ter um pipe para o main

//echo ola | grep ola

/* 
1-> echo ola
2-> grep ola
3-> grep ola | para main */