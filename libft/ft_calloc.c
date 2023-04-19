/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:08:52 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/24 11:40:51 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Asigna espacio de memoria contiguo rellenando la memoria con 0
// RETURN puntero a la memoria asignada
void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem == 0)
		return (mem);
	ft_bzero (mem, count * size);
	return (mem);
}
