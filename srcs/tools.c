/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:01:56 by akram             #+#    #+#             */
/*   Updated: 2023/07/27 17:57:39 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

	if (i == SIGINT || i == SIGQUIT)
		terminate(i);
	byte = ft_recode(i);
	if (byte > 0)
		ft_fill_list(byte);
	if (byte == '\0')
		ft_print_list();
}
