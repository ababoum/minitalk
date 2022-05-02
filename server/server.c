/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:59:30 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 16:29:37 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_data	g_data;

void	concat_char_in_msg(unsigned char c)
{
	char	*new_msg;
	size_t	init_len;


	init_len = ft_strlen(g_data.msg_in_chars);
	new_msg = malloc_log(2 + init_len);
	ft_memcpy_talk(new_msg, g_data.msg_in_chars);
	new_msg[init_len] = c;
	// printf("char = %i\n", new_msg[init_len]);
	new_msg[init_len + 1] = 0;
	g_data.msg_in_chars = new_msg;
}

void	add_char(void)
{
	int				c;
	int				i;

	c = 0;
	i = -1;
	while (g_data.msg[++i])
		c += ((g_data.msg[i] - '0') * ft_pow(2, i));
	printf("integer: %i\n", c);
	if (c == 127)
	{
		g_data.end = 1;
	}
	else
		concat_char_in_msg((unsigned char)c);
	empty_str(g_data.msg, 9);
}

void	process_msg(void)
{
	int	i;

	i = -1;
	while (g_data.msg_in_chars[++i])
	{
		if (g_data.msg_in_chars[i] != 2)
			g_data.pid_src = g_data.pid_src * 10 + (g_data.msg_in_chars[i] - '0');
		else
		{
			i++;
			break ;
		}
	}
	kill(g_data.pid_src, SIGUSR1);
	ft_putstr_fd(g_data.msg_in_chars + i, 1);
	ft_putstr_fd("\n", 1);
	reset_msg();
}

int	main(void)
{
	init_data();
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, get_bit);
	signal(SIGUSR2, get_bit);
	while (1)
	{
		while (!g_data.end)
			pause();
		process_msg();
	}
	return (EXIT_SUCCESS);
}
