/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:14 by afonso            #+#    #+#             */
/*   Updated: 2023/01/06 16:09:50 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_signal_behaviour(int signo)
{
	//This is just a prototype, not actual code
	if (signo == CTRL_C)
	{
		printf("\n");
	}
	if (signo == CTRL_BS)
	{
		exit(0);
	}
}

void	signal_handler(void)
{
	struct sigaction sa;

	sa.handler = change_signal_behaviour;
	sigaction(CTRL_C, &sa, NULL);
	sigaction(CTRL_BS, &sa, NULL);
}