/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:51:57 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/11/25 14:15:49 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	c;

	c = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}	
	while (str[c])
	{
		write (1, &str[c], 1);
		c++;
	}
	return (c);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		count = 11;
	}
	else if (n < 0)
	{
		write (1, "-", 1);
		n = n * -1;
		count++;
	}
	if (n >= 0 && n <= 9)
		count += ft_putchar(n + 48);
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + 48);
	}
	return (count);
}
