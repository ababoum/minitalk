/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:59:00 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 16:29:18 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define RED_TXT	"\e[31;1m"
# define RESET_TXT	"\e[0m"

typedef struct s_memlog {
	void			*ptr;
	struct s_memlog	*next;
	int				type;
}	t_memlog;

typedef struct s_data {
	t_memlog	*mem_lst;
	char		*msg_in_chars;
	char		msg[9];
	int			end;
	int			pid_src;
}	t_data;

// void	get_zero(int code);
// void	get_one(int code);
void	get_bit(int signum);
void	init_data(void);
void	reset_msg(void);
void	add_char(void);
size_t	ft_strlen(char *str);
void	ft_putnbr_fd(int n, int fd);
void	empty_str(char *ptr, size_t count);
void	*ft_memcpy_talk(char *dest, char *src);
void	exit_message(char *message, int exit_code);
void	ft_putstr_fd(char *s, int fd);
void	*malloc_log(int size);
int		ft_pow(int nb, int power);

#endif