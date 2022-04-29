/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:00:27 by mababou           #+#    #+#             */
/*   Updated: 2022/04/29 22:05:48 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

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

void	*ft_memset(void *ptr, int val, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		((char *)ptr)[i++] = val;
	return (ptr);
}

void	*ft_memcpy_talk(char *dest, char *src)
{
	size_t		i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	return (dest);
}

