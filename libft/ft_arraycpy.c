/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraycpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:09:26 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/04/14 10:56:18 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_arraycpy(int *dst, int *array, int len)
{
	int	c;

	c = 0;
	if (!array || len == 0)
		return (NULL);
	while (c < len)
	{
		dst[c] = array[c];
		c++;
	}
	return (dst);
}
