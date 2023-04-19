/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:31:49 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/26 15:33:11 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Genera una string que representa el valor entero recibido como 
//argumento convertido a char (con malloc)
//RETURN la strinr que represente el num, NULL si falla la memoria
static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*number;
	size_t	count;

	nb = n;
	count = ft_len(n);
	number = (char *)ft_calloc(sizeof(char), count + 1);
	if (number == 0)
		return (0);
	if (nb == 0)
	{
		number[0] = '0';
		return (number);
	}
	if (nb < 0)
	{
		number[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		number[(count--) - 1] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (number);
}

// int	main(void)
// {
// 	printf ("%s\n", ft_itoa(-2147483648));
// 	return (0);
// }