/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:02:03 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/28 12:51:50 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Copia 'n' bytes desde *src a *dst. SI se superponen el comportamiento es 
// indefinido. en las aplicaciones que las string pudiean solaparse habria que 
// usar memmove
// RETURN 	el valor de dst, si las dos string estan vacias 0
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cpy;

	cpy = 0;
	if (!dst && !src)
		return (0);
	while (cpy < n)
	{
		((unsigned char *)dst)[cpy] = ((unsigned char *)src)[cpy];
		cpy++;
	}
	return (dst);
}
