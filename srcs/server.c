/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akram <akram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:01:56 by akram             #+#    #+#             */
/*   Updated: 2023/06/12 18:45:24 by akram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler()
{
    write(STDOUT_FILENO, "I won't die\n", 13);
}

int main()
{
    int pid;
    signal(SIGINT, handler);
    pid = getpid();
    while (1)
    {
        printf("le PID vaut == %d\n", pid);
        sleep(1);
    }
}
