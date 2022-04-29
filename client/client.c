/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:15:52 by mababou           #+#    #+#             */
/*   Updated: 2022/04/29 21:24:56 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

void	reception_confirmation(int code)
{
	(void)code;
	ft_putstr(1, "The server received your message!\n");
	exit(EXIT_SUCCESS);
}

static void	send_char(int c, char *dest_pid)
{
	int	i;

	i = 8;
	while (i)
	{
		if (c % 2)
			kill(ft_atoi(dest_pid), SIGUSR1);
		else
			kill(ft_atoi(dest_pid), SIGUSR2);
		c = c / 2;
		i--;
	}
}

static int	send_pid(int pid, char *dest_pid)
{
	char	*pid_str;
	int		i;

	pid_str = ft_itoa(pid);
	if (!pid_str)
	{
		ft_putstr(2, "Malloc failure\n");
		return (1);
	}
	i = 0;
	while (pid_str[i])
		send_char(pid_str[i++], dest_pid);
	return (0);
}

void	send_message(char *msg, char *dest_pid)
{
	int	c;
	int	i;

	i = 0;
	while (msg[i])
	{
		c = msg[i];
		if (c < 0)
			send_char(1, dest_pid);
		send_char(c, dest_pid);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		exit_error("Wrong parameters. Usage: ./client <PID> <MESSAGE>");
	if (send_pid(getpid(), av[1]))
		return (EXIT_FAILURE);
	send_char(0, av[1]);
	send_message(av[2], av[1]);
	send_char(127, av[1]);
	signal(SIGUSR1, reception_confirmation);
}
