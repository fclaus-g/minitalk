/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:41:32 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/10/24 12:28:45 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Reserva con malloc un array de string resultante de separar *s en 
//substrings usando como separador 'c', el array debe terminar en un 
//puntero NULL
// RETURN el array de nuevas strings o NULL si falla la reserva de memoria.
// Para ello en primer lugar contamos el tamaño que va a tener nuestro array
// contando el num de palabras de s con una funcion usandoun mecanismo de
// bandera

static int	ft_countwords(const char *str, char c)
{
	int	nword;
	int	flag;
	int	count;

	nword = 0;
	flag = -1;
	count = 0;
	while (str[count])
	{
		if (str[count] != c && flag < 0)
		{
			flag = 0;
			nword++;
		}
		else if (str[count] == c)
			flag = -1;
		count++;
	}
	return (nword);
}
//Luego creamos una funcion que copie las palabras en las strings

static char	*ft_copyword(const char *str, int start, int finish)
{
	char	*word;
	int		count;

	count = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
	{
		word[count] = str[start];
		count++;
		start++;
	}
	word[count] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	c1;
	size_t	c2;
	int		flag;
	char	**split;

	split = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (split == 0)
		return (0);
	c1 = 0;
	c2 = 0;
	flag = -1;
	while (c1 <= ft_strlen(s))
	{
		if (s[c1] != c && flag < 0)
			flag = c1;
		else if ((s[c1] == c || c1 == ft_strlen(s)) && flag >= 0)
		{
			split[c2] = ft_copyword(s, flag, c1);
			c2++;
			flag = -1;
		}
		c1++;
	}
	split[c2] = 0;
	return (split);
}
