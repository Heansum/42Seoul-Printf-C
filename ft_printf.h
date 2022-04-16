/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlim <hlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:41:30 by hlim              #+#    #+#             */
/*   Updated: 2022/04/16 17:24:11 by hlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_putadr(unsigned long int nb);
int	ft_puthex(unsigned int nb, int s);
int	ft_putstr(char *str);
int	format_checker(char c, va_list *ap);
int	ft_printf(const char *format, ...);

#endif
