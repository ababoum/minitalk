/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:15:52 by mababou           #+#    #+#             */
/*   Updated: 2022/05/03 17:38:14 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

// int	g_bit_confirmed;

static void	final_message(void)
{
	ft_putstr(1, GREEN_TXT);
	ft_putstr(1, "The server received your message!\n");
	ft_putstr(1, RESET_TXT);
	exit(EXIT_SUCCESS);
}

static void	reception_confirmation(int signum)
{
	if (signum == SIGUSR1)
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

static void	send_message(char *msg, char *dest_pid)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_char((unsigned char)msg[i], dest_pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, reception_confirmation);
	if (ac != 3)
	{
		ft_putstr(2, RED_TXT);
		exit_error("Wrong parameters. Usage: ./client <PID> <MESSAGE>");
		ft_putstr(2, RESET_TXT);
	}
	if (ft_atoi(av[1]) <= 0)
	{
		ft_putstr(2, RED_TXT);
		exit_error("Destination PID needs to be > 0");
		ft_putstr(2, RESET_TXT);
	}
	send_message(av[2], av[1]);
	send_char(END_CHAR, av[1]);
	while (1)
		;
}
