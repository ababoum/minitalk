/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:59:00 by mababou           #+#    #+#             */
/*   Updated: 2022/05/07 15:25:15 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define RED_TXT	"\e[31;1m"
# define BLUE_TXT	"\e[34;1m"
# define RESET_TXT	"\e[0m"

# define END_CHAR	127

typedef struct s_char {
	unsigned char	c;
	struct s_char	*next;
}	t_char;

size_t	ft_strlen(char *str);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memcpy_talk(char *dest, char *src);
void	exit_message(char *message, int exit_code);
void	ft_putchar(unsigned char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_pow(int nb, int power);
// chained list
void	ft_lstadd_back(t_char **alst, t_char *new);
t_char	*ft_lstnew(unsigned char c);
void	ft_lstiter(t_char *lst, void (*f)(unsigned char));
t_char	*ft_lstlast(t_char *lst);
void	ft_lstclear(t_char **lst);

#endif