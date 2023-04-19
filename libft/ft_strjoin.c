/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:23:16 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/24 11:43:56 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//concatena s1 y s2 y las almacena en una nueva cadena usando malloc
//RETURN la nueva string. NULL si falla la resrva de memoria
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	count;
	size_t	c2;
	size_t	lens3;

	lens3 = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)malloc(sizeof(char) * lens3);
	count = 0;
	c2 = 0;
	if (s3 == 0)
		return (0);
	while (count < ft_strlen(s1))
	{
		s3[count] = s1[count];
		count++;
	}
	while (c2 < ft_strlen(s2))
	{
		s3[count + c2] = s2[c2];
		c2++;
	}
	s3[count + c2] = 0;
	return (s3);
}
