/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:05:12 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/24 11:48:10 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Concatena src al finasl de dat, dst size - strlen -1
//RETURN la longitud total de dst despues de la copia, si dstsize que el tamaño 
//de dst o dstsize es == 0 RETURN dstsize + tamaño de src 
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	copier;
	size_t	c2;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	copier = lendst;
	c2 = 0;
	if (dstsize <= lendst || dstsize == 0)
		return (dstsize + lensrc);
	while (src[c2] != '\0' && c2 < dstsize - lendst - 1)
	{
		dst[copier] = src[c2];
		copier++;
		c2++;
	}
	dst[copier] = '\0';
	return (lendst + lensrc);
}
/*
int	main(void)
{
	size_t	dstsize;
	char	*dst;
	const char	*src;

	dst = "hola";
	src = "quease";
	dstsize = 5;
	ft_strlcat(dst, src, dstsize);
	printf("%s\n", dst);
	printf("%zu\n", ft_strlcat(dst, src, dstsize));
	return(0);
}*/