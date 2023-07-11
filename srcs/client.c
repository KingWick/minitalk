/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:54:27 by akram             #+#    #+#             */
/*   Updated: 2023/07/10 18:56:04 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// La condition while (byte != 0 || i < 8) est utilisée dans la fonction ft_decode pour déterminer quand arrêter l'envoi des bits d'un octet.
// L'objectif de cette boucle est d'envoyer chaque bit de l'octet (8 bits au total) en utilisant les signaux SIGUSR1 et SIGUSR2.
// La boucle se poursuit tant que l'octet n'a pas été entièrement envoyé
// (c'est-à-dire que byte n'est pas égal à zéro) ou tant que tous les 8 bits n'ont pas été envoyés (c'est-à-dire que i est inférieur à 8).
// La condition byte != 0 vérifie si tous les bits de l'octet ont été envoyés.
// Lorsque tous les bits sont envoyés, l'octet est devenu zéro car chaque bit a été décalé vers la droite et est tombé à zéro.
// La condition i < 8 vérifie si tous les 8 bits de l'octet ont été traités.
// La variable i est utilisée pour suivre le nombre de bits déjà envoyés. Lorsque i atteint la valeur 8, cela signifie que tous les 8 bits ont été envoyés.
// En résumé, la condition while (byte != 0 || i < 8) garantit que tous les bits de l'octet sont envoyés avant de sortir de la boucle,
// évitant ainsi la perte de données ou l'envoi incomplet de l'octet.

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
		usleep(20);
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
	if (ac != 3)
	{
		ft_printf("\033[91mError\033[0m\n");
		ft_printf("\033[33mTry: ./client [PID] [MESSAGE]\033[0m\n");
		return (1);
	}
	ft_send(atoi(av[1]), av[2]);
}
