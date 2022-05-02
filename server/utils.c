/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:00:27 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 21:27:38 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

extern t_data	g_data;

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	empty_str(int code, size_t count)
{
	size_t	i;

	i = 0;
	if (code == 0)
	{
		while (i < count)
			g_data.msg[i++] = '\0';
	}
	else
	{
		while (i < count)
			g_data.msg_in_chars[i++] = '\0';
	}
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