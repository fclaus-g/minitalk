/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:41:39 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/24 12:09:27 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//compara 'n' caracteres entre s1 y s2. Los caracteres que aparecen despues 
//de'\0' no se comparan.
//RETURN un int < o > que 0 utilizando unsigned char
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n && (s1[count] || s2[count]))
	{
		if (s1[count] != s2[count])
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		count++;
	}	
	return (0);
}
/*
int	main(void)
{
	const char	*s1;
	const char	*s2;
	size_t	n;

	s1 = "abcdef";
	s2 = "abc\xfdxx";
	n = 5;
	printf("La diferencia es: %d\n", ft_strncmp(s1, s2, n));
	return (0);
	
}*/
