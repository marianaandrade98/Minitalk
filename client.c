/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:31:50 by mandrade          #+#    #+#             */
/*   Updated: 2021/11/12 18:46:54 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** it shifts right to send the signals, bit by bit, right to left.
** it sends the SIGUSR1 for 0 and SIGUSR2 for 1.
** uses the usleep() function to give time to give the data correctly, and
**		there is no data loss.
*/

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) % 2 == 0)
		{
			kill(pid, SIGUSR1);
			usleep(25);
		}
		if ((c >> i) % 2 == 1)
		{
			kill(pid, SIGUSR2);
			usleep(25);
		}
		i--;
	}
}

/*
**	takes a message and sends it to send_char() char by char. In that function
**		we send the data, bit by bit, to server.
*/

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		ft_putstr_fd("Invalid Arguments\n", 1);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_char(pid, argv[2][i]);
		i++;
	}
}
