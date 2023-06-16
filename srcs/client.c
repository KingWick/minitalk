/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:54:27 by akram             #+#    #+#             */
/*   Updated: 2023/06/16 17:26:25 by akdjebal         ###   ########.fr       */
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
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid,SIGUSR2);
		}
		byte = byte >> 1;
		i++;

	}
}

void	ft_send(int pid, char *str)
{
	int i;
	i = 0;

	while (str[i])
	{
		ft_decode(str[i], pid);
		i++;
	}
}

int main(int ac, char **av)
{
    if (ac != 3)
	{
		ft_printf("E")
	}
}
