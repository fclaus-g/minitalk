/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:03:08 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/24 12:22:55 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//elimina los caracteres de la string set del principio y final de s1 hasta
//encontrar un caracter no perteneciente a set. La string resultante se 
//devuelve con una reserva de malloc. No borra los caracteres que esten entre
//texto
//RETURN ,si set o s1 == 0 return NULL.
//primero creamos una funcion que detecte si set contiene contiene c.
int	ft_checkset(int c, const char *set)
{
	size_t	count;

	count = 0;
	while (set[count])
	{
		if (set[count] == c)
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	c1;
	size_t	c2;
	char	*new;
	size_t	lennew;
	size_t	copy;

	if (!s1 || !set)
		return (0);
	c1 = 0;
	c2 = ft_strlen(s1);
	while (s1[c1] && ft_checkset(s1[c1], set))
		c1++;
	while (c2 > c1 && ft_checkset(s1[c2 - 1], set))
		c2--;
	lennew = c2 - c1 + 1;
	new = (char *)malloc(sizeof(char) * lennew);
	if (new == 0)
		return (0);
	copy = 0;
	while (c1 < c2)
	{
		new[copy++] = s1[c1++];
	}
	new[copy] = 0;
	return (new);
}
