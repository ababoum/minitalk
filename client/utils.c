/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:18:18 by mababou           #+#    #+#             */
/*   Updated: 2022/05/03 17:41:33 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(int fd, char *str)
{
	if (write(fd, str, ft_strlen(str)) == -1)
		exit_error("Fatal error");
}

void	exit_error(char *message)
{
	ft_putstr(2, message);
	ft_putstr(2, "\n");
	exit(EXIT_FAILURE);
}
