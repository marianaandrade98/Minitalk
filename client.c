/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:10:06 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/28 08:59:19 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
**	first, it checks if the command line parameters are valid.
**		If it's not, the program displays an error message and exits with
**		EXIT_FAILURE.
**
**	The program continues running and prepares itself to receive either SIGUSR1,
**		in case everything is working acordingly in server, or SIGUSR2 in case
**		of errors from server. The signal() function is used with
**		confirmation() function being called once these signals are received.
**
**	After the signal() functions are all set, the program sends the first bit
**		server using the send_bit() function with argv[1] (PID) and argv[2]
**		(message). This is the only time send_bit() is called with non null
**		parameters. This only happens because of its static variables
**
**	After sending the first bit of message, and making the first contact with
**		server, client enters an infinite loop of pause() functions waiting
**		for either SIGUSR1 or SIGUSR2. If all goes well and the message is
**		delivered , client will only receive SIGUSR1 signals from server.
**		These signals are the acknowledgement from server that it received a
**		bit from client.
*/

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_str_isnumeric(argv[1]))
	{
		ft_putstr_fd("Client: Invalid Arguments.\n", 2);
		ft_putstr_fd("Correct Format: ./client <PID> <MESSAGE>\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, confirmation);
	signal(SIGUSR2, confirmation);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}

/*
**	It is called everytime client receives a signal from server.
**	If the signal received is SIGUSR1, means that server confirms receiving a
**		bit from client and is ready to receive another.
**	If it is SIGUSR2, means that an error occurred in server, causing it to
**		quit unexpectedly, then client outputs an error message and exits
**		with EXIT_FAILURE.
*/

void	confirmation(int signum)
{
	int	end;

	end = 0;
	if (signum == SIGUSR1)
		end = send_bit(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd("client: server exited unexpectedly\n", 2);
		exit(EXIT_FAILURE);
	}
	if (end)
	{
		ft_putstr_fd("client: Operation successful\n", 1);
		exit(EXIT_SUCCESS);
	}
}

/*
**	Sends a bit from 'message' everytime its called.
**	In case all the bits from 'message' were already sent to server, the
**		function calls the send_null(). It sends 8 SIGUSR1 representing the null
**		character and signaling the end of the string. Once all 8 bits are sent
**		to server, 'message' is freed and the function returns 1, telling
**		confirmation() that it finally sent the string.
*/

int	send_bit(int pid, char *str)
{
	static char	*message = 0;
	static int	s_pid = 0;
	static int	bits = -1;

	if (str)
		message = ft_strdup(str);
	if (!message)
		client_error(0);
	if (pid)
		s_pid = pid;
	if (message[++bits / 8])
	{
		if (message[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				client_error(message);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			client_error(message);
		return (0);
	}
	if (!send_null(s_pid, message))
		return (0);
	free(message);
	return (1);
}

/*
**	It is called when all the bits from message were received by server.
**		Sends 8 SIGUSR1 signals representing the null character in binary.
**		Once i = 8, and all zeros (SIGUSR1) were sent, the function returns 1.
*/

int	send_null(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			client_error(str);
		return (0);
	}
	return (1);
}

/*
**	It is called in case an error occurred in a kill() system call in clent.
**		It frees 'str', displays an error message and then exits the program.
*/

void	client_error(char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("client: unexpected error.\n", 2);
	exit(EXIT_FAILURE);
}
