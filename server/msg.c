/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:05:00 by mababou           #+#    #+#             */
/*   Updated: 2022/04/29 20:19:46 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

// static t_msg	*ft_lstlast(t_msg *lst)
// {
// 	t_msg	*tmp;

// 	tmp = lst;
// 	if (tmp)
// 		while (tmp->next)
// 			tmp = tmp->next;
// 	return (tmp);
// }

// void	ft_lstadd_back(t_msg **alst, t_msg *new)
// {
// 	if (*alst)
// 		ft_lstlast(*alst)->next = new;
// 	else
// 		*alst = new;
// }

// t_msg	*ft_lstnew(t_data *data, int c)
// {
// 	t_msg	*new;

// 	new = malloc_log(data, sizeof(t_msg));
// 	if (!new)
// 		return (0);
// 	new->value = c;
// 	new->next = 0;
// 	return (new);
// }
