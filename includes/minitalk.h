/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:57:47 by akram             #+#    #+#             */
/*   Updated: 2023/07/27 17:42:28 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}				t_list;

typedef struct s_env
{
	struct s_list	*head;
	struct s_list	*last;
}				t_env;

t_list	*ft_fill_list(int octet);
void	ft_clean_list(t_list *list);
void	ft_handler(int i);
void	ft_print_list(void);
void	ft_decode(int pid, int byte);
int		ft_recode(int bit);
void	ft_send(int pid, char *str);
void	terminate(int code);

#endif