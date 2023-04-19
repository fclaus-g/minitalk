/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:26:18 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/24 12:14:26 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Localiza la ultima aparicion de c(convertido en char) en la string 
//apuntada por s.
//RETURN un puntero a la localizacion de c, o NULL si el caracter no aparece
char	*ft_strrchr(const char *s, int c)
{
	size_t	count;
	char	*last;
	char	*cpy;

	cpy = (char *)s;
	count = 0;
	last = 0;
	while (count < ft_strlen(cpy))
	{
		if (cpy[count] == (char)c)
			last = &cpy[count];
		count++;
	}
	if ((char)c == cpy[count])
		return (&cpy[count]);
	return (last);
}
/*
int main() 
{
    const char *str = "heea";
    char  c;
   
    c = 'a';
    printf("Found letter:%c\n", *ft_strrchr(str, c));
   return (0);
}*/