/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:52:15 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/18 12:04:28 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"
#include "../../define.h"
#include "../../minishell.h"
#include <errno.h>
//we need exit built-in so we can free all resources before we exit

// int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
// int	kill(pid_t pid, int sig)

static void	intrv_signal_handler(int sig_num)
{
	char	*p;

	if (sig_num == SIGINT)
	{
		write(1, "\n", 1);
		p = print_prompt(0);
		printf(" ");
		free (p);
	}
	if (sig_num == SIGQUIT)
		return ;
	return ;
}

static void	nintrv_signal_handler(int sig_num)
{
	if (sig_num == SIGQUIT || sig_num == SIGINT)
	{
		g_struct.chad_exitstatus = 4;
		exit(4);
	}
}

void	intr_behaviour(struct sigaction *act)
{
	act->sa_handler = intrv_signal_handler;
	act->sa_flags = SA_RESTART;
	sigaction(SIGINT, act, NULL);
	act->sa_handler = SIG_IGN;
	sigaction(SIGQUIT, act, NULL);
	return ;
}

void	nintr_behaviour(struct sigaction *act)
{
	act->sa_handler = nintrv_signal_handler;
	act->sa_flags = SA_RESTART;
	sigaction(SIGINT, act, NULL);
	sigaction(SIGQUIT, act, NULL);
	return ;
}
