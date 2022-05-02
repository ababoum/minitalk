/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:59:30 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 21:23:18 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_data	g_data;

void	concat_char_in_msg(unsigned char c)
{
	size_t	init_len;

	init_len = ft_strlen(g_data.msg_in_chars);
	g_data.msg_in_chars[init_len] = c;
	g_data.msg_in_chars[init_len + 1] = '\0';
}

void	process_msg(void)
{
	ft_putstr_fd(g_data.msg_in_chars, 1);
	ft_putstr_fd("\n", 1);
	reset_msg();
}

void	add_char(void)
{
	int				c;
	int				i;

	c = 0;
	i = -1;
	while (++i < 8)
		c += ((g_data.msg[i] - '0') * ft_pow(2, i));
	if (c != 127)
		concat_char_in_msg((unsigned char)c);
	else
		g_data.end = 1;
	empty_str(g_data.msg, 9);
}

int	main(void)
{
	struct sigaction	sa;

	g_data.msg_in_chars = calloc(INT_MAX, 1);
	g_data.msg[0] = 0;
	reset_msg();
	ft_putstr_fd(BLUE_TXT, 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(RESET_TXT, 1);
	ft_putstr_fd("\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_bit;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1) ({});
	return (EXIT_SUCCESS);
}
