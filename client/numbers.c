/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:43:44 by mababou           #+#    #+#             */
/*   Updated: 2022/04/29 20:45:32 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	output;

	i = 0;
	output = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		output = output * 10 + (str[i++] - '0');
	return (sign * output);
}

static int	nb_len(long int n)
{
	if (n >= 0 && n <= 9)
		return (1);
	else
		return (1 + nb_len(n / 10));
}

char	*ft_itoa(int n)
{
	int				sign;
	unsigned int	nb;
	char			*output;
	int				i;

	sign = 0;
	if (n < 0)
		sign = 1;
	nb = (1 - 2 * sign) * n;
	i = nb_len(nb) - 1 + sign;
	output = malloc(i + 2);
	if (!output)
		return (NULL);
	if (sign == 1)
		output[0] = '-';
	output[i + 1] = 0;
	while (i >= sign)
	{
		output[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (output);
}
