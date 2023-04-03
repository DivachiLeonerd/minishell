/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:52:15 by atereso-          #+#    #+#             */
/*   Updated: 2023/04/03 18:02:19 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"
#include "../../define.h"
#include "../../minishell.h"
#include <errno.h>
//we need exit built-in so we can free all resources before we exit

// int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
// int	kill(pid_t pid, int sig)

static void    intrv_signal_handler(int sig_num)
{
	char *p;
	
	if (sig_num == SIGINT)
	{
		printf("\n");
		printf(PROMPT);
		p = ft_pwd();
		printf("%s$ ", p);
		free (p);
	}
	return ;
}

static void	nintrv_signal_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		chad_exitstatus = 130;
		exit(130);
	}
}

void	intr_behaviour(struct sigaction *act)
{
	act->sa_handler = intrv_signal_handler;
	act->sa_flags = SA_RESTART;
	sigaction(SIGINT, act, NULL);
	return ;
}

void	nintr_behaviour(struct sigaction *act)
{
	act->sa_handler = nintrv_signal_handler;
	act->sa_flags = SA_RESTART;
	sigaction(SIGINT, act, NULL);
	return ;
}
