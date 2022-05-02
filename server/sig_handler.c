/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:03:53 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 16:32:58 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

extern t_data	g_data;

void	get_bit(int signum)
{
	size_t	init_len;

	init_len = ft_strlen(g_data.msg);
	if (signum == SIGUSR1)
	{
		g_data.msg[init_len] = '0';
	}
	else
	{
		g_data.msg[init_len] = '1';
	}
	if (init_len == 7)
	{
		printf("final character: %s, ", g_data.msg);
		add_char();
	}
}

void	init_data(void)
{
	g_data.mem_lst = 0;
	reset_msg();
}

void	reset_msg(void)
{
	empty_str(g_data.msg, 9);
	g_data.msg_in_chars = malloc_log(sizeof(char));
	if (!g_data.msg_in_chars)
		exit_message("Malloc failure", EXIT_FAILURE);
	g_data.msg_in_chars[0] = 0;
	g_data.end = 0;
	g_data.pid_src = 0;
}
