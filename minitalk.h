/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:10:19 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/28 05:17:13 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

void	signal_handler(int signum, siginfo_t *info, void *context);
char	*print_str(char *message);
void	kill_error(int pid, char *str);

#endif
