/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlim <hlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:12:01 by hlim              #+#    #+#             */
/*   Updated: 2022/04/16 17:15:05 by hlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long long	n;
	int			len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
		len += ft_putchar(nb + 48);
	return (len);
}

int	ft_putadr(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_putadr(nb / 16);
		len ++ ft_putadr(nb % 16);
	}
	else
	{
		if (nb < 10)
			len += ft_putnbr(nb + 48);
		else
			len += ft_putnbr(nb + 87);
	}
	return (len);
}

int	ft_putunbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_putunbr(nb / 10);
		len += ft_putunbr(nb % 10);
	}
	else
		len += ft_putchar(nb + 48);
	return (len);
}

int	ft_puthex(unsigned int nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_puthex(nb / 16, s);
		len += ft_puthex(nb % 16, s);
	}
	else
	{
		if (nb < 10)
			len += ft_putchar(nb + 48);
		else
		{
			if (s == 1)
				len += ft_putchar(nb + 87);
			else
				len += ft_putchar(nb + 55);
		}
	}
	return (len);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}
