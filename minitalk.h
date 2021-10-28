/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:10:19 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/28 08:24:25 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

/*
**	Server
*/
void	signal_handler(int signum, siginfo_t *info, void *context);
char	*print_str(char *message);
void	server_error(int pid, char *str);

/*
**	Client
*/
void	confirmation(int signum);
int		send_bit(int pid, char *str);
int		send_null(int pid, char *str);
void	client_error(char *str);

#endif
