/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:23:33 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/27 18:40:13 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 0 && nb <= 9)
	{
		count += ft_putchar(nb + '0');
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb <= 9)
	{
		count += ft_putchar(nb + '0');
	}
	else if (nb >= 10)
	{
		count += ft_putnbr_u(nb / 10);
		count += ft_putnbr_u(nb % 10);
	}
	return (count);
}
