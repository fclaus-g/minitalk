/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:24:48 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/11/05 17:04:47 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Reserva con malloc y devuelve una substring de s. La sub string empieza 
//desde start y tiene una longitud de len.
//RETURN la string resultante o NULL si falla la reserva de memoria
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			count;
	char			*sub;
	size_t			slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen)
		len = slen - start;
	sub = (char *)malloc(sizeof (char) * len + 1);
	if (sub == 0)
		return (0);
	count = 0;
	while (s[count] && (count < len))
	{	
		sub[count] = s[start + count];
		count++;
	}
	sub[count] = 0;
	return (sub);
}
