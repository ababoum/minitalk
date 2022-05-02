/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:03:53 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 21:28:03 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

extern t_data	g_data;

void	get_bit(int signum, siginfo_t *info, void *context)
{
	size_t	init_len;

	(void)context;
	g_data.pid_src = info->si_pid;
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
		add_char();
	}
	if (g_data.end == 1)
		process_msg();
	if (kill(g_data.pid_src, SIGUSR2))
	{
		exit_message("Cannot send a signal to client", EXIT_FAILURE);
	}
}

void	reset_msg(void)
{
	empty_str(0, 9);
	empty_str(1, 1);
	g_data.end = 0;
}
