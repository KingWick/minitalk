/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akram <akram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:01:56 by akram             #+#    #+#             */
/*   Updated: 2023/06/15 19:55:26 by akram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int i)
{
    (void)i;
    write(STDOUT_FILENO, "Fuck you\n", 13);
}

int main()
{
    int pid;
    int *p = NULL;
    p = malloc(sizeof(*p));
    signal(SIGINT, &handler);
    

    pid = getpid();
    while (1)
    {
        printf("le PID vaut == %d\n", pid);
        sleep(1);
    }
}
