/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:59:00 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 21:27:49 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define RED_TXT	"\e[31;1m"
# define BLUE_TXT	"\e[34;1m"
# define RESET_TXT	"\e[0m"

typedef struct s_data {
	char		msg[9];
	char		*msg_in_chars;
	int			end;
	int			pid_src;
}	t_data;

void	get_bit(int signum, siginfo_t *info, void *context);
void	reset_msg(void);
void	process_msg(void);
void	add_char(void);
size_t	ft_strlen(char *str);
void	ft_putnbr_fd(int n, int fd);
void	empty_str(int code, size_t count);
void	*ft_memcpy_talk(char *dest, char *src);
void	exit_message(char *message, int exit_code);
void	ft_putstr_fd(char *s, int fd);
int		ft_pow(int nb, int power);

#endif