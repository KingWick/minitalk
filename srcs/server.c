/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:01:56 by akram             #+#    #+#             */
/*   Updated: 2023/07/11 20:23:53 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void ft_clean_list(t_list *list)
{
	if (list && list->next)
		ft_clean_list(list->next);
	free(list);
	list = NULL;
}	

int	ft_recode(int bit)
{
	static int	i;
	static int	byte;
	char		res;

	if (bit == SIGUSR1)
		bit = 1;
	else if (bit == SIGUSR2)
		bit = 0;
	byte = byte + (bit << i);
	i++;
	if (i == 8)
	{
		res = byte;
		byte = 0;
		i = 0;
		return (res);
	}
	return (-1);
}

void	ft_handler(int i)
{
	int	byte;

	byte = ft_recode(i);
	if (byte > 0)
		ft_fill_list(byte);
	if (byte == '\0')
		ft_print_list();
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
	printf("\n");
	
	ft_clean_list(g_env.head);
	g_env.head = NULL;
	g_env.last = NULL;

}

void	ft_fill_list(int octet)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	// if (!new)
	// 	return (NULL);
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
}

int	main(void)
{
	// if (!g_env)
	// 	return (NULL);
	g_env.head = NULL;
	g_env.last = NULL;
	ft_printf("The server pid is : %d\n", getpid());
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
	{
	}
}
