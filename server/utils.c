/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:00:27 by mababou           #+#    #+#             */
/*   Updated: 2022/05/03 17:41:08 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

extern t_data	g_data;

void	ft_putstr_fd(char *s, int fd)
{
	if (write(fd, s, ft_strlen(s)) == -1)
		exit_message("Fatal error", EXIT_FAILURE);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy_talk(char *dest, char *src)
{
	size_t		i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	return (dest);
}

void	exit_message(char *message, int exit_code)
{
	ft_putstr_fd(RED_TXT, 2);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(exit_code);
	ft_putstr_fd(RESET_TXT, 2);
}
