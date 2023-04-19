/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:57:02 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/14 18:55:34 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char    *str;

	str = "estrella galicia";
	printf ("%d\n", ft_strlen(str));
	printf ("%lu\n", strlen(str));
	return(0);
}*/