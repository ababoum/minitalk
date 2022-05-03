/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:59:00 by mababou           #+#    #+#             */
/*   Updated: 2022/05/03 17:44:24 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define RED_TXT	"\e[31;1m"
# define BLUE_TXT	"\e[34;1m"
# define RESET_TXT	"\e[0m"

# define END_CHAR	127

typedef struct s_data {
	int			pid_src;
}	t_data;

size_t	ft_strlen(char *str);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memcpy_talk(char *dest, char *src);
void	exit_message(char *message, int exit_code);
void	ft_putstr_fd(char *s, int fd);
int		ft_pow(int nb, int power);

#endif