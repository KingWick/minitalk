/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:15:46 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/27 18:45:40 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_base_ptr(unsigned long long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_putnbr_base_ptr(nbr / 16, base);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	ft_putnbr_base_xx(unsigned int nbr, char c)
{
	int		count;
	char	*base;
	char	*base_maj;

	base = "0123456789abcdef";
	base_maj = "0123456789ABCDEF";
	count = 0;
	if (c == 'x')
	{
		if (nbr >= 16)
			count += ft_putnbr_base_xx(nbr / 16, c);
		count += ft_putchar(base[nbr % 16]);
		return (count);
	}
	else
	{
		if (nbr >= 16)
			count += ft_putnbr_base_xx(nbr / 16, c);
		count += ft_putchar(base_maj[nbr % 16]);
		return (count);
	}
}
