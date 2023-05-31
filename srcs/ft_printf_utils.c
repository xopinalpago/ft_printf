/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:04:38 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/15 10:19:39 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_pointer(unsigned long nb)
{
	if (nb == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		ft_putstr("0x");
		return (ft_putnbr_hexa(nb) + 2);
	}
}

int	ft_putnbr_hexa(unsigned long nb)
{
	int	cpt;

	cpt = 0;
	if (nb >= 16)
	{
		cpt += ft_putnbr_hexa(nb / 16);
		cpt += ft_putnbr_hexa(nb % 16);
	}
	else
	{
		if (nb < 10)
			cpt += ft_putchar(nb + '0');
		else
			cpt += ft_putchar(nb - 10 + 'a');
	}
	return (cpt);
}

int	ft_putnbr(int nb)
{
	long	n;
	int		cpt;

	cpt = 0;
	n = nb;
	if (n < 0)
	{
		cpt += ft_putchar('-');
		n = n * -1;
	}
	if (n > 9)
	{
		cpt += ft_putnbr(n / 10);
	}
	cpt += ft_putchar((n % 10) + '0');
	return (cpt);
}

int	ft_putnbr_base(unsigned int nb, char *base, unsigned int lbase)
{
	int	cpt;

	cpt = 0;
	if (nb < lbase)
		cpt += ft_putchar(base[nb]);
	if (nb >= lbase)
	{
		cpt += ft_putnbr_base(nb / lbase, base, lbase);
		cpt += ft_putnbr_base(nb % lbase, base, lbase);
	}
	return (cpt);
}
