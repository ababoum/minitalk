/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:59:30 by mababou           #+#    #+#             */
/*   Updated: 2022/04/29 21:23:49 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_data	*get_data(int code, t_data *input)
{
	static t_data	*data_ptr;

	if (code == 0)
		return (data_ptr);
	else
	{
		data_ptr = input;
		input->mem_lst = 0;
		ft_memset(input->msg, 0, 9);
		input->msg_in_chars = malloc_log(input, 1);
		if (!input->msg_in_chars)
			exit_message(input, "Malloc failure", EXIT_FAILURE);
		input->msg_in_chars[0] = 0;
		input->end = 0;
		input->pid_src = 0;
		input->unicode = 0;
		return (0);
	}
}

void	concat_char_in_msg(t_data *data, int c)
{
	char	*new_msg;
	size_t	init_len;

	init_len = ft_strlen(data->msg_in_chars);
	new_msg = malloc_log(data, 2 + init_len);
	ft_memcpy(new_msg, data->msg_in_chars, init_len);
	if (data->unicode)
	{
		new_msg[init_len] = -c;
		data->unicode--;
	}
	else
		new_msg[init_len] = c;
	new_msg[init_len + 1] = 0;
	ft_memset(data->msg, 0, 9);
	data->msg_in_chars = new_msg;
}

void	add_char(t_data *data)
{
	int		c;
	int		i;

	c = 0;
	i = -1;
	while (data->msg[++i])
		c += (data->msg[i] * ft_pow(2, i));
	if (c == 1)
	{
		data->unicode = 3;
		ft_memset(data->msg, 0, 9);
		return ;
	}
	else if (c == 127)
	{
		data->end = 1;
		return ;
	}
	else
		concat_char_in_msg(data, c);
}

void	process_msg(t_data *data)
{
	int	i;

	i = 0;
	while (data->msg_in_chars[i])
	{
		if (data->msg_in_chars[i] != 2)
			data->pid_src = data->pid_src * 10 + (data->msg_in_chars[i] - '0');
		else
		{
			i++;
			break ;
		}
	}
	kill(data->pid_src, SIGUSR1);
	ft_putstr_fd(data->msg_in_chars + i, 1);
}

int	main(void)
{
	t_data	data;
	int		empty;

	get_data(!0, &data);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, get_zero);
	signal(SIGUSR2, get_one);
	while (!data.end)
		(void)empty;
	process_msg(&data);
	return (EXIT_SUCCESS);
}
