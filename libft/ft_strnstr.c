/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:26:24 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/24 12:12:04 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Busca la secuencia de caracteresde needle dentro de haystack y en caso de que 
// se encuentre indicara en que posicion aparece.
//RETURN si needle es null - haystack, si needle no esta en haystack NULL
//si needle esta en haystack &haystack[x]
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;
	size_t	c2;
	char	*cpy;

	c = 0;
	c2 = 0;
	cpy = ((char *)haystack);
	if (*needle == 0)
		return (cpy);
	if (len == 0)
		return (0);
	while (cpy[c] && c < len && len > 0)
	{
		c2 = 0;
		while (needle[c2] && cpy[c + c2] == needle[c2] && c + c2 < len)
			c2++;
		if (needle[c2] == 0)
			return (&cpy[c]);
		c++;
	}
	return (0);
}
/*
int	main(void) 
{
	const char	*haystack;
	const char	*needle;
	size_t	len;

	haystack = "estrella galicia";
	needle = "tr";
	len = 4;
	printf ("la coincidencia se da en %s", ft_strnstr(haystack, needle, len));
	return 0;
}*/