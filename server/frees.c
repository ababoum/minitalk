/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:11:42 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 16:12:04 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

extern t_data	g_data;

static void	ft_lstclear(void)
{
	t_memlog	*tmp;
	t_memlog	*tmp_next;

	tmp = g_data.mem_lst;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp->ptr);
		free(tmp);
		tmp = tmp_next;
	}
	g_data.mem_lst = NULL;
}

static void	clear_exit(int exit_code)
{
	ft_lstclear();
	exit(exit_code);
}

void	exit_message(char *message, int exit_code)
{
	ft_putstr_fd(RED_TXT, 2);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	clear_exit(exit_code);
	ft_putstr_fd(RESET_TXT, 2);
}
