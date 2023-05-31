/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:05:28 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/15 10:20:53 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_hexa(unsigned long nb);
int	ft_putnbr(int nb);
int	ft_putnbr_base(unsigned int nb, char *base, unsigned int lbase);
int	ft_type(va_list argptr, const char type);
int	ft_printf(const char *str, ...);
int	ft_pointer(unsigned long nb);

#endif
