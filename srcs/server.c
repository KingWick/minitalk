/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:01:56 by akram             #+#    #+#             */
/*   Updated: 2023/06/16 14:34:16 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int i)
{
	if (i == SIGUSR1)
	{
		
		printf("signal SIGUSER1 recu\n");
	}
	else if (i == SIGUSR2)
	{
		
		printf("signal SIGUSER2 recu\n");
	}
}


int main()
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	
	printf("The server pid is %d\n", getpid());
	while (1)
	{
		pause();
	}
	
}
