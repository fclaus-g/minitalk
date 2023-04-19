/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:17:04 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/04/18 13:47:28 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	send_message(int pid, char *message)
{
	int	byte;
	int	bit_pos;

	byte = 0;
	while (message[byte] != '\0')
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
		ft_printf("Wrong number of arguments\n");
		ft_printf("Usage: ./client [server PID] [message]\n");
		return (-1);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	ft_printf("%s\n", message);
	send_message(pid, message);
	return (0);
}
