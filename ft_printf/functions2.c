/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:30:54 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/11/25 14:36:16 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long int n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_putpointer(n / 16);
		count += ft_putchar(hex[n % 16]);
	}
	else
		count += ft_putchar(hex[n]);
	return (count);
}

int	ft_putunsign(unsigned long int n)
{
	int	count;

	count = 0;
	if (n < 0)
		n = n * -1;
	if (n >= 10)
	{
		count += ft_putunsign(n / 10);
		count += ft_putchar(n % 10 + 48);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}

int	ft_puthex(unsigned int n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_puthex(n / 16);
		count += ft_putchar(hex[n % 16]);
	}
	else
		count += ft_putchar(hex[n]);
	return (count);
}

int	ft_puthexup(unsigned int n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_puthexup(n / 16);
		count += ft_putchar(hex[n % 16]);
	}
	else
		count += ft_putchar(hex[n]);
	return (count);
}
