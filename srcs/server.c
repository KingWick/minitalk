/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:01:56 by akram             #+#    #+#             */
/*   Updated: 2023/07/27 17:57:20 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct s_env	g_env;

void	terminate(int code)
{
	ft_clean_list(g_env.head);
	if (code == 2)
		exit(130);
	exit(131);
}

void	ft_clean_list(t_list *list)
{
	if (list && list->next)
		ft_clean_list(list->next);
	free(list);
	list = NULL;
}

void	ft_print_list(void)
{
	t_list	*tmp;

	tmp = g_env.head;
	while (tmp)
	{
		ft_printf("%c", tmp->data);
		tmp = tmp->next;
	}
	ft_clean_list(g_env.head);
	g_env.head = NULL;
	g_env.last = NULL;
}

t_list	*ft_fill_list(int octet)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = octet;
	new->next = NULL;
	if (g_env.head == NULL)
	{
		g_env.head = new;
		g_env.last = new;
	}
	else
	{
		g_env.last->next = new;
		g_env.last = g_env.last->next;
	}
	return (new);
}

int	main(void)
{
	g_env.head = NULL;
	g_env.last = NULL;
	ft_printf("The server pid is : %d\n", getpid());
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, ft_handler);
	while (1)
	{
	}
}
