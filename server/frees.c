/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:11:42 by mababou           #+#    #+#             */
/*   Updated: 2022/04/29 20:21:56 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

static void	ft_lstclear(t_data *data)
{
	t_memlog	*tmp;
	t_memlog	*tmp_next;

	tmp = data->mem_lst;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp->ptr);
		free(tmp);
		tmp = tmp_next;
	}
	data->mem_lst = NULL;
}

static void	clear_exit(t_data *data, int exit_code)
{
	if (data)
		ft_lstclear(data);
	exit(exit_code);
}

void	exit_message(t_data *data, char *message, int exit_code)
{
	ft_putstr_fd(RED_TXT, 2);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	clear_exit(data, exit_code);
	ft_putstr_fd(RESET_TXT, 2);
}
