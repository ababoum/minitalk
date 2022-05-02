/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:15:52 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 16:35:32 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

void	reception_confirmation(int code)
{
	(void)code;
	ft_putstr(1, GREEN_TXT);
	ft_putstr(1, "The server received your message!\n");
	ft_putstr(1, RESET_TXT);
	exit(EXIT_SUCCESS);
}

static void	send_char(unsigned char c, char *dest_pid)
{
	int	i;

	i = 0;
	printf("%i: ", c);
	while (i < 8)
	{
		usleep(5000);
		if (c % 2 == 0)
		{
			printf("0");
			kill(ft_atoi(dest_pid), SIGUSR1);
		}
		else
		{
			printf("1");
			kill(ft_atoi(dest_pid), SIGUSR2);
		}
		c = c / 2;
		i++;
	}
	printf("\n");
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
	free(pid_str);
	return (0);
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
	if (ac != 3)
		exit_error("Wrong parameters. Usage: ./client <PID> <MESSAGE>");
	if (send_pid(getpid(), av[1]))
		return (EXIT_FAILURE);
	send_char(2, av[1]);
	printf("\n");
	send_message(av[2], av[1]);
	send_char(127, av[1]);
	signal(SIGUSR1, reception_confirmation);
	pause();
}
