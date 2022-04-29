/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:59:00 by mababou           #+#    #+#             */
/*   Updated: 2022/04/29 22:13:53 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define RED_TXT	"\e[31;1m"
# define RESET_TXT	"\e[0m"

typedef struct s_memlog {
	void			*ptr;
	struct s_memlog	*next;
	int				type;
}	t_memlog;

typedef struct s_data {
	t_memlog	*mem_lst;
	char		msg[9];
	char		*msg_in_chars;
	int			end;
	int			pid_src;
	int			unicode;
}	t_data;

void	get_zero(int code);
void	get_one(int code);
t_data	*get_data(int code, t_data *input);
void	reset_msg(t_data *data);
void	add_char(t_data *data);
size_t	ft_strlen(char *str);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *ptr, int val, size_t count);
void	*ft_memcpy_talk(char *dest, char *src);
void	exit_message(t_data *data, char *message, int exit_code);
void	ft_putstr_fd(char *s, int fd);
void	*malloc_log(t_data *data, int size);
int		ft_pow(int nb, int power);

#endif