/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:53:57 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/20 03:36:28 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"

/* 
 * If for some reason the code get_next_line does not compile with the 
 * -D BUFFER_SIZE=<int> - if BUFFER_SIZE is not defined, BUFFER_SIZE will be
 * defined with 1 as it's value.
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin_helper(char *s1, char *s2);

#endif
