/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:03:53 by mababou           #+#    #+#             */
/*   Updated: 2022/04/29 22:13:41 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

void	get_zero(int code)
{
	t_data	*data;
	size_t	init_len;

	(void)code;
	data = get_data(0, 0);
	init_len = ft_strlen(data->msg);
	data->msg[init_len] = '0';
	if (init_len == 7)
		add_char(data);
}

void	get_one(int code)
{
	t_data	*data;
	size_t	init_len;

	(void)code;
	data = get_data(0, 0);
	init_len = ft_strlen(data->msg);
	data->msg[init_len] = '1';
	if (init_len == 7)
		add_char(data);
}

t_data	*get_data(int code, t_data *input)
{
	static t_data	*data_ptr;

	if (code == 0)
		return (data_ptr);
	else
	{
		data_ptr = input;
		input->mem_lst = 0;
		reset_msg(input);
		return (0);
	}
}
