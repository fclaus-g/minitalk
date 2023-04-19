/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:16:38 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/09/29 14:03:24 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	a;

	a = 'A';
	ft_tolower (a);
	printf ("%d\n", ft_tolower(a));
	a = ft_tolower(a);
	write (1, &a, 1);
	return (0);
}*/