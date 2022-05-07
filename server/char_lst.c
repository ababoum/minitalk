/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:10:23 by mababou           #+#    #+#             */
/*   Updated: 2022/05/07 15:26:11 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_char	*ft_lstlast(t_char *lst)
{
	t_char	*tmp;

	tmp = lst;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_char **alst, t_char *new)
{
	if (*alst)
		ft_lstlast(*alst)->next = new;
	else
		*alst = new;
}

t_char	*ft_lstnew(unsigned char c)
{
	t_char	*list;

	list = malloc(sizeof(t_char));
	if (!list)
		exit_message("Malloc: fatal error", EXIT_FAILURE);
	list->c = c;
	list->next = 0;
	return (list);
}

void	ft_lstiter(t_char *lst, void (*f)(unsigned char))
{
	t_char	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->c);
		tmp = tmp->next;
	}
}

void	ft_lstclear(t_char **lst)
{
	t_char	*tmp;
	t_char	*tmp_next;

	tmp = *lst;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	*lst = NULL;
}
