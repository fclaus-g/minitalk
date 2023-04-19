/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:05:15 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/04/14 10:56:39 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	copier;

	copier = 0;
	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[copier] != '\0')
	{
		dst[copier] = src[copier];
		copier++;
	}
	dst[copier] = '\0';
	return (dst);
}
