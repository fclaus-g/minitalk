/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:51:05 by fernandocla       #+#    #+#             */
/*   Updated: 2023/04/18 13:51:12 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		write(fd, "-2147483648", 11);
	else if (nb >= 0 && nb <= 9)
		ft_putchar_fd(nb + 48, fd);
	else if (nb < 0)
	{
		nb = -nb;
		write(fd, &sign, 1);
		ft_putnbr_fd(nb, fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nb % 10 + 48, fd);
	}
}

void	handler(int signal, siginfo_t *info, void *vacio)
{
	static int		bit_pos = 7;
	static char		byte;
	static pid_t	client_pid;

	client_pid = info->si_pid;
	(void)vacio;
	if (signal == SIGUSR1)
		byte |= (1 << bit_pos);
	bit_pos--;
	if (bit_pos < 0)
	{
		if (byte == '\0')
		{
			kill(client_pid, SIGUSR1);
			byte = 0;
			bit_pos = 7;
			write (1, "\n", 1);
		}
		kill(client_pid, SIGUSR2);
		ft_putchar_fd(byte, 1);
		byte = 0;
		bit_pos = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf(MAGENTA_T"Server PID: %d\n", getpid());
	ft_printf(CYAN_T"Waiting message...\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
