/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:15:52 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 20:30:01 by mababou          ###   ########.fr       */
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
	// g_bit_confirmed = 1;
}

static void	send_char(unsigned char c, char *dest_pid)
{
	int				i;
	unsigned char	original_char;
	// int	empty;

	i = 0;
	original_char = c;
	// printf("%i: ", c);
	while (i < 8)
	{
		if (c % 2 == 0)
		{
			// printf("0");
			kill(ft_atoi(dest_pid), SIGUSR1);
		}
		else
		{
			// printf("1");
			kill(ft_atoi(dest_pid), SIGUSR2);
		}
		pause();
		c = c / 2;
		i++;
		// g_bit_confirmed = 0;
		if (original_char == 127 && i == 8)
		{
			// pause();
			final_message();
		}
	}
	// printf("\n");
}

// static int	send_pid(int pid, char *dest_pid)
// {
// 	char	*pid_str;
// 	int		i;

// 	pid_str = ft_itoa(pid);
// 	if (!pid_str)
// 	{
// 		ft_putstr(2, "Malloc failure\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (pid_str[i])
// 		send_char(pid_str[i++], dest_pid);
// 	free(pid_str);
// 	return (0);
// }

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
	// g_bit_confirmed = 0;
	signal(SIGUSR2, reception_confirmation);
	if (ac != 3)
		exit_error("Wrong parameters. Usage: ./client <PID> <MESSAGE>");
	send_message(av[2], av[1]);
	send_char(127, av[1]);
}
