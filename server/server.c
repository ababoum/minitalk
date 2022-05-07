/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:59:30 by mababou           #+#    #+#             */
/*   Updated: 2022/05/07 15:52:33 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

static unsigned char	byte_to_char(const char *msg)
{
	int	c;
	int	i;

	c = 0;
	i = -1;
	while (++i < 8)
		c += ((msg[i] - '0') * ft_pow(2, i));
	return ((unsigned char)c);
}

static void	get_bit(int signum, siginfo_t *info, void *context)
{
	static char		byte[9];
	static size_t	pos_byte = 0;
	static t_char	*msg = 0;

	(void)context;
	if (signum == SIGUSR1)
		byte[pos_byte++] = '0';
	else if (signum == SIGUSR2)
		byte[pos_byte++] = '1';
	if (pos_byte == 8)
	{
		pos_byte = 0;
		if (byte_to_char(byte) == END_CHAR)
		{
			ft_lstiter(msg, ft_putchar);
			ft_putchar('\n');
			ft_lstclear(&msg);
		}
		else
			ft_lstadd_back(&msg, ft_lstnew(byte_to_char(byte)));
	}
	if (!usleep(100) && kill(info->si_pid, SIGUSR1))
		exit_message("Cannot send a signal to client", EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			ss;

	sigemptyset(&ss);
	sa.sa_mask = ss;
	sigaddset(&ss, SIGUSR1);
	sigaddset(&ss, SIGUSR2);
	sa.sa_sigaction = get_bit;
	sa.sa_flags = SA_SIGINFO;
	{
		ft_putstr_fd(BLUE_TXT, 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putstr_fd(RESET_TXT, 1);
		ft_putstr_fd("\n", 1);
	}
	if (sigaction(SIGUSR1, &sa, 0) || sigaction(SIGUSR2, &sa, 0))
		exit_message("Error setting signal processing", EXIT_FAILURE);
	while (1)
		;
	return (EXIT_SUCCESS);
}
