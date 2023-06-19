/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:01:56 by akram             #+#    #+#             */
/*   Updated: 2023/06/19 14:37:35 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int ft_recode(int bit)
{
	static int i;
	static int byte;
	char res;
	
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

void ft_handler(int i)
{
	int byte;
	byte = ft_recode(i);
	if (byte > 0)
		ft_fill_list(byte);
	if (byte == '\0')
		ft_print_list();
}
// 
//-------handler version tableau deja pret----------//


void ft_print_list()
{
	t_list *tmp;

	tmp = env->head;
	while (tmp)
	{
		ft_printf("%c", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	env->head = NULL;
	env->last = NULL;
}

void ft_fill_list(int octet)
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	
	new->data = octet;
	new->next = NULL;

	if (env->head == NULL)
	{
		env->head = new;
		env->last = new;
	}
	else
	{
		env->last->next = new;
		env->last = env->last->next;
	}
	

	// char str[256];
	// static int index = 0;
	
	// int byte = ft_recode(i);
	
	// if (byte > 0)
	// {
	// 	str[index] = byte;
	// 	index++;
	// }
	
	// if (byte == '\0')
	// {
	// 	str[index] = '\0';
	// 	ft_printf("%s\n", str);
	// 	index = 0;
	// }
}


int main()
{
	env = malloc(sizeof(t_env));
	env->head = NULL;
	env->last = NULL;
	ft_printf("The server pid is : %d\n", getpid());
	
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	
	while (1){}
}
