/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:09:34 by mababou           #+#    #+#             */
/*   Updated: 2022/05/02 16:12:11 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

extern t_data	g_data;

static t_memlog	*new_mem(void *ptr)
{
	t_memlog	*new;

	new = malloc(sizeof(t_memlog));
	if (!new)
		exit_message("Malloc failure", EXIT_FAILURE);
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

static t_memlog	*mem_lstlast(t_memlog *lst)
{
	t_memlog	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static void	mem_add_back(t_memlog **alst, t_memlog *new)
{
	t_memlog	*last;

	if (*alst)
	{
		last = mem_lstlast(*alst);
		last->next = new;
	}
	else if (*alst == NULL)
		*alst = new;
}

void	*malloc_log(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_message("Malloc failure", EXIT_FAILURE);
	mem_add_back(&(g_data.mem_lst), new_mem(ptr));
	return (ptr);
}
