/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:07:16 by schiper           #+#    #+#             */
/*   Updated: 2025/03/18 14:12:58 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

static int	handle_format(const char **format, va_list list)
{
	int	byte;

	byte = 0;
	if (**format == 'd' || **format == 'i')
		byte += ft_putnbr(va_arg(list, int));
	else if (**format == 's')
		byte += ft_putstr(va_arg(list, char *));
	else if (**format == 'c')
		byte += ft_putchar(va_arg(list, int));
	else if (**format == 'x')
		byte += ft_puthex(va_arg(list, unsigned int), "0123456789abcdef");
	else if (**format == 'X')
		byte += ft_puthex(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (**format == 'p')
		byte += ft_putptr(va_arg(list, void *));
	else if (**format == '%')
		byte += ft_putchar('%');
	else if (**format == 'u')
		byte += ft_putunbr(va_arg(list, unsigned int));
	return (byte);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		byte;

	byte = 0;
	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			byte += handle_format(&format, list);
		}
		else
			byte += ft_putchar(*format);
		format++;
	}
	va_end(list);
	return (byte);
}
