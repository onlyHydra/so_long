/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:12:57 by schiper           #+#    #+#             */
/*   Updated: 2025/03/25 19:31:03 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long num, const char *hex)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += ft_puthex(num / 16, hex);
	}
	write(1, &hex[num % 16], 1);
	count++;
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	if (addr == 0)
		return (ft_putstr1("(nil)"));
	write(1, "0x", 2);
	return (ft_puthex(addr, "0123456789abcdef") + 2);
}

int	ft_putunbr(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10);
	c = (n % 10) + '0';
	count += ft_putchar1(c);
	return (count);
}
