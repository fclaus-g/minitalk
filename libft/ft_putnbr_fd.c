/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:50:06 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/28 15:34:46 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// int	main(void)
// {
// 	printf ("")
// }