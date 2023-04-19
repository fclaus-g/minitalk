/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:43:25 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/09/30 13:41:45 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int	main(void)
{
	int	a;

	a = 'a';
	printf ("%d\n", (ft_toupper(a)));
	a = ft_toupper(a);
	write (1, &a, 1);
	write (1, " ", 1);
	return (0);	
	el programa imprime 65 que es el valor ascii pero no el caracter, 
	posible putchar la funcion en si está bien
}
*/
