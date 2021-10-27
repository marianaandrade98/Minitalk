/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:10:27 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/27 22:42:06 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	signal_handler(int signum, siginfo_t *info, void *context)
{
	//continue
}

/*
**	It starts by setting up the function that will receive the signals from
**		a client, sigaction(), used in order to get the parameter 'info->pid'
**		the pid of the sender, the client.
**	Then, server uses the function getpid() to output to the user its PID. 
**		which will be used to compile client.
**	Then, it enters an infinite pause() loop waiting for the signals from
**		client.
*/

int	main(void)
{
	struct sigaction	sa_sig;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_sig.sa_handler = 0;
	sa_sig.sa_flags = SA_SIGINFO;
	sa_sig.sa_mask = block_mask;
	sa_sig.sa_sigaction = // continue
}
