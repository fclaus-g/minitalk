/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:46:35 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/26 17:11:12 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	count;
	char	*new;

	if (s == 0)
		return (0);
	count = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (new == 0)
		return (0);
	while (s[count])
	{
		new[count] = f(count, s[count]);
		count++;
	}
	new[count] = 0;
	return (new);
}
