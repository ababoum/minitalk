/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:15:52 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 21:41:45 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

// int	g_bit_confirmed;

void	final_message(void)
{
	ft_putstr(1, GREEN_TXT);
	ft_putstr(1, "The server received your message!\n");
	ft_putstr(1, RESET_TXT);
	exit(EXIT_SUCCESS);
}

void	reception_confirmation(int signum)
{
	if (signum == SIGUSR2)
		(void)signum;
}

static void	send_char(unsigned char c, char *dest_pid)
{
	int				i;
	unsigned char	original_char;

	i = 0;
	original_char = c;
	while (i < 8)
	{
		if (c % 2 == 0)
		{
			if (kill(ft_atoi(dest_pid), SIGUSR1))
				exit_error("Fatal error");
		}
		else
		{
			if (kill(ft_atoi(dest_pid), SIGUSR2))
				exit_error("Fatal error");
		}
		pause();
		c = c / 2;
		i++;
		if (original_char == 127 && i == 8)
		{
			final_message();
		}
	}
}

void	send_message(char *msg, char *dest_pid)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_char(msg[i], dest_pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	signal(SIGUSR2, reception_confirmation);
	if (ac != 3)
		exit_error("Wrong parameters. Usage: ./client <PID> <MESSAGE>");
	send_message(av[2], av[1]);
	send_char(127, av[1]);
}
