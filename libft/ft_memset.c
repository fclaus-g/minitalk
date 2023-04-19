/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:32:48 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/24 11:31:54 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Igual que bzero, pero le da el valor de 'c' convertido en unsigned char
// no RETURN
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	del;

	del = 0;
	while (del < len)
	{
		((char *)b)[del] = ((unsigned char)c);
		del++;
	}
	return (b);
}
