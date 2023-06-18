/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:01:56 by akram             #+#    #+#             */
/*   Updated: 2023/06/18 16:39:27 by akdjebal         ###   ########.fr       */
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
		ft_printf("%c", byte);
	if (byte == '\0')
		ft_printf("\n");
}

//-------handler version tableau deja pret----------//

// void ft_handler(int i)
// {
// 	char str[256];
// 	static int index = 0;
	
// 	int byte = ft_recode(i);
	
// 	if (byte > 0)
// 	{
// 		str[index] = byte;
// 		index++;
// 	}
	
// 	if (byte == '\0')
// 	{
// 		str[index] = '\0';
// 		ft_printf("%s\n", str);
// 		index = 0;
// 	}
// }


int main()
{
	ft_printf("The server pid is : %d\n", getpid());
	
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	
	while (1)
	{
		pause();
	}
	
}
