/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:14:01 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/04/19 13:36:17 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		sign;

	sign = '-';
	nb = n;
	if (nb == -2147483648)
		write (fd, "-2147483648", 11);
	else if (nb >= 0 && nb <= 9)
		ft_putchar_fd(nb + 48, fd);
	else if (nb < 0)
	{
		nb = -nb;
		write (fd, &sign, 1);
		ft_putnbr_fd (nb, fd);
	}
	else
	{
		ft_putnbr_fd (nb / 10, fd);
		ft_putchar_fd (nb % 10 + 48, fd);
	}
}

void	handler(int signal)
{
	static int	bit_pos = 7;
	static char	byte;

	if (signal == SIGUSR1)
		byte |= (1 << bit_pos);
	bit_pos--;
	if (bit_pos < 0)
	{
		ft_putchar_fd(byte, 1);
		byte = 0;
		bit_pos = 7;
	}
}

int	main(void)
{
	ft_printf(VERDE_T"Server PID: %d\n", getpid());
	ft_printf(MAGENTA_T"Waiting message...\n");
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
