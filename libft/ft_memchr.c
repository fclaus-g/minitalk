/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:07:26 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/28 12:53:04 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Localiza la primera ocurrencia de 'c' ,convertida en unsigned char, en *s
// RETURN un puntero al byte localizado o NULL si no existe tal byte
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*string;
	unsigned char	c2;

	count = 0;
	string = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (count < n)
	{
		if (string[count] == c2)
			return (&string[count]);
		count++;
	}
	return (0);
}
