/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlim <hlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:43:51 by hlim              #+#    #+#             */
/*   Updated: 2022/04/16 17:52:11 by hlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	format_checker(char c, va_list *ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*ap, int));
	else if (c == '%')
		len += write(1, "%", 1);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(*ap, int));
	else if (c == 'u')
		len += ft_putunbr(va_arg(*ap, unsigned int));
	else if (c == 'x')
		len += ft_puthex(va_arg(*ap, unsigned int), 1);
	else if (c == 'X')
		len += ft_puthex(va_arg(*ap, unsigned int), 2);
	else if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_putadr(va_arg(*ap, unsigned long int));
	}
	else if (c == 's')
		len += ft_putstr(va_arg(*ap, char *));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		else
		{
			len += format_checker(format[i + 1], &ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
