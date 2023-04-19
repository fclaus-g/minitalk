/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:49:17 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/28 12:17:31 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// convierte la parte inicial de una string apuntada por str a una 
//representacion int, escanea la string, omite los caracteres en blanco 
//y no inicia la conversion hasta que encuentra un num o un signo.
// RETURN el char convertido a int o 0 si str no se puede convertir o es NULL
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

// int	main(void)
// {
// 	printf("la string es %d", ft_atoi("  123a45"));
// 	return (0);
// }