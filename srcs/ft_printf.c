/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:46:21 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/15 15:47:00 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_type(va_list argptr, const char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg(argptr, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(argptr, char *)));
	else if (type == 'p')
		return (ft_pointer(va_arg(argptr, unsigned long)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(argptr, int)));
	else if (type == 'u')
		return (ft_putnbr_base(va_arg(argptr, unsigned int),
				"0123456789", 10));
	else if (type == 'x')
		return (ft_putnbr_base(va_arg(argptr, unsigned int),
				"0123456789abcdef", 16));
	else if (type == 'X')
		return (ft_putnbr_base(va_arg(argptr, unsigned int),
				"0123456789ABCDEF", 16));
	else if (type == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cpt;
	va_list	argptr;

	va_start(argptr, str);
	cpt = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			cpt += ft_type(argptr, str[i + 1]);
			i++;
		}
		else
			cpt += ft_putchar(str[i]);
		i++;
	}
	va_end(argptr);
	return (cpt);
}
