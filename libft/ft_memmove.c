/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:14:31 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/11/02 14:47:22 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Copia los bytes de src a dst, si las dos string se superponen la copia se 
// hara de una manera no destructiva, la diferencia con memcpy es que memmove 
// utiliza un buffer intermedio que permite que las zonas de memoria esten 
// solapadas
// RETURN dst o NULL si dst o src son NULL
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	cpy;

	cpy = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src < dst)
	{
		while (len != 0)
		{
			len--;
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	else
	{
		while (cpy < len)
		{
			((char *)dst)[cpy] = ((char *)src)[cpy];
			cpy++;
		}
	}
	return (dst);
}
