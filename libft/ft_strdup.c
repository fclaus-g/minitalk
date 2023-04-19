/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:44:12 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/24 11:42:52 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Reserva con malloc suficiente memoria para s1 y hace la copia
//RETURN un puntero a la copia, el puntero puede ser usado como arg para free  
char	*ft_strdup(const char *s1)
{
	size_t		count;
	size_t		len;
	char		*copy;

	count = 0;
	len = ft_strlen(s1) + 1;
	copy = malloc(sizeof(char) * len);
	if (copy == 0)
		return (0);
	while (s1[count])
	{
		copy[count] = s1[count];
		count++;
	}
	copy[count] = 0;
	return (copy);
}

// int	main(void)
// {
// 	const char *s1 = "tabataba";

// 	ft_strdup(s1);
// 	return (0);
// }