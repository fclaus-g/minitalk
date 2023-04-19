/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:04:15 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/28 13:14:16 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Pone a 0 los primeros 'n' de bytes de una string, no RETURN
void	ft_bzero(void *s, size_t n)
{
	size_t	del;

	del = 0;
	while (del < n)
	{
		((char *)s)[del] = 0;
		del++;
	}
}
