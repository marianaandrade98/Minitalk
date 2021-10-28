/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:10:27 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/28 09:30:08 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	sa_sig.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa_sig, NULL);
	sigaction(SIGUSR2, &sa_sig, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}

/*
**	it is called every time the server receives a signal (SIGUSR1 or SIGUSR2)
**		from client.
**	SIGUSR1 represents a 0 and SIGUSR2 represents 1. By getting this signals
**		from client, server is able to recreate the string, receiving it bit
**		by bit, using bitwise operations.
**
**	It starts by adding the bit (0 or 1) depending on the signal it received
**		from client, in a static variable type char 'c'.
**
**	When 8 signals are received, it is called 8 times. Then, the character is
**		complete and is added to another static variable 'message'.
**
**	If the character received is a NULL character, nothing more is added to
**		'message' and then prints the message, that is set to NULL.
**
**	After receiving the signal and successfully storing the bit in the string,
**		server sends a SIGUSR1 signal to client as confirmation.
*/

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits = 0;
	static int	pid = 0;
	static char	*message = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			message = ft_straddc(message, c);
		else
			message = print_str(message);
		bits = 0;
		c = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
		server_error(pid, message);
}

/*
**	it is called once server received the full string  'message' from client.
**		This function outputs 'message' and then frees it, returning zero.
*/

char	*print_str(char *message)
{
	ft_putstr_fd(message, 1);
	free(message);
	return (NULL);
}

/*
**	It is called in case an error occurred in kill() system call in server.
**		It frees 'str' if not null and before exiting the program with
**		EXIT_FAILURE it outputs an error message, and tries to send SIGUSR2
**		to client signaling an error.
*/

void	server_error(int pid, char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("Server: unexpected error.\n", 2);
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}
