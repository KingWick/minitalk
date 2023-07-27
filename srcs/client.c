/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:54:27 by akram             #+#    #+#             */
/*   Updated: 2023/07/27 18:16:03 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long	ft_atoi(char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	if (!(*str >= '0' && *str <= '9'))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		if ((result * sign) <= 0 || (result * sign) > INT_MAX)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		str++;
	}
	return (result * sign);
}

void	ft_decode(int pid, int byte)
{
	int	i;

	i = 0;
	while (byte != 0 || i < 8)
	{
		if (byte % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		byte = byte >> 1;
		usleep(50);
		i++;
	}
}

void	ft_send(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_decode(pid, str[i]);
		i++;
	}
	ft_decode(pid, '\0');
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("\033[91mError\033[0m\n");
		ft_printf("\033[33mTry: ./client [PID] [MESSAGE]\033[0m\n");
		return (1);
	}
	else
	{
		pid = ft_atoi(av[1]);
		if (kill(pid, 0) <= -1)
		{
			ft_printf("\033[91mError\033[0m\n");
			ft_printf("\033[33mThe PID: %s is invalid\033[0m\n", av[1]);
			return (1);
		}
		ft_send(ft_atoi(av[1]), av[2]);
	}
}
