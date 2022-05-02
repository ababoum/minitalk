/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:53:21 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 15:25:07 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

int	ft_pow(int nb, int power)
{
	int	res;

	res = 1;
	while (power)
	{
		res *= nb;
		power--;
	}
	return (res);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	else
		nb = n;
	if (nb <= 9)
		ft_putchar_fd(nb + '0', fd);
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
}
