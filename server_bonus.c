/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:28:11 by mandrade          #+#    #+#             */
/*   Updated: 2021/11/17 17:53:18 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	i = 7;
	static char	c = 0;

	(void)ucontext;
	if (sig == SIGUSR2)
		c += (1 << i);
	i--;
	if (i < 0)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	pid = getpid();
	act.sa_sigaction = signal_handler;
	act.sa_flags = SA_SIGINFO;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
