/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:47:49 by mandrade          #+#    #+#             */
/*   Updated: 2021/11/12 20:12:18 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
**	when it receives the signal 1 (SIGUSR2) it left shifts the number 1, 
**		by the bit position of the intended char, and adds it to c, until it 
**		gets the whole char.
**	by that time, i will be equal to -1, so writes the char and we restart i
**		and c, so we can take another char properly.
*/

void	signal_handler(int signal)
{
	static int	i = 7;
	static char	c = 0;
	
	if (signal == SIGUSR2)
		c += (1 << i);
	i--;
	if (i < 0)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
}

/*
**	this function gets and writes the PID, so we can use it on client.
**	then, receives the signals from there and converts them into char
**		to display char by char.
*/

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
