/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:33:19 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/28 12:54:54 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Compara los n bytes de s1 con s2
// RETURN 0 si s1 == s2, o la diferencia de los dos primeros bytes que difieren
// tratados como unsigned char
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			count;
	size_t			c2;

	count = 0;
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (count < n)
	{
		if (string1[count] != string2[count])
		{
			c2 = (unsigned char)string1[count] - (unsigned char)string2[count];
			return (c2);
		}
		count++;
	}
	return (0);
}
