/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:54:27 by akram             #+#    #+#             */
/*   Updated: 2023/06/18 19:04:57 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_decode(int pid, int byte)
{
	int i;
	i = 0;

	while (byte != 0 || i < 8)
	{
		if (byte % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		byte = byte >> 1;
		usleep(20);
		i++;
	}
}

void	ft_send(int pid, char *str)
{
	int i;
	i = 0;

	while (str[i])
	{
		ft_decode(pid, str[i]);
		i++;
	}
	ft_decode(pid, '\0');
}

int main(int ac, char **av)
{
    if (ac != 3)
	{
		ft_printf("\033[91mError\033[0m\n");
		ft_printf("\033[33mTry: ./client [PID] [MESSAGE]\033[0m\n");
		return (1);
	}
	ft_send(atoi(av[1]), av[2]);
}
