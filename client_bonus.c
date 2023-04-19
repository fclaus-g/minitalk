/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:51:12 by fernandocla       #+#    #+#             */
/*   Updated: 2023/04/19 13:26:31 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t	count;
	size_t	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (ft_isdigit(str[count]))
	{
		result = result * 10 + str[count] - 48;
		count++;
	}
	return (sign * result);
}

void	handler(int signal)
{
	static int	bytes = 0;

	if (signal == SIGUSR2)
	{
		bytes++;
	}
	if (signal == SIGUSR1)
	{
		ft_printf(GREEN_T"Message received. Size %d bytes\n", bytes);
		exit (0);
	}
}

void	send_message(int pid, char *message)
{
	int	byte;
	int	bit_pos;

	byte = 0;
	while (message[byte] + 1)
	{
		bit_pos = 7;
		while (bit_pos > -1)
		{
			if (message[byte] & (1 << bit_pos))
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}	
			bit_pos--;
			usleep(50);
		}
		byte++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;

	if (ac != 3)
	{
		printf(RED_T"Wrong number of arguments\n");
		printf(GREEN_T"Usage: ./client [server PID] [message]\n");
		return (-1);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	printf("%s\n", message);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_message(pid, message);
	while (9)
		pause();
	return (0);
}
