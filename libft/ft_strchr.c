/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:37:25 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/24 11:40:48 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Localiza la primera aparicion de 'c' convertida en char en la cadena 
//apuntada por s el caracter NULL de la string se considera parte de la string
//por tanto si c = '\0' la funcion localiza la terminacion.
//RETURN un puntero a la primera concurrencia de c
char	*ft_strchr(const char *s, int c)
{
	size_t	count;
	char	*x;

	count = 0;
	x = (char *)s;
	while (count <= ft_strlen(x))
	{
		if (x[count] == (char)c)
			return (&x[count]);
		count++;
	}
	return (0);
}
/*
int main() 
{
    const char *str = "heea";
    char  c;
   
    c = 'a';
    printf("Found letter:%c\n", *ft_strchr(str, c));
   
    return (0);
}*/