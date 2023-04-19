/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:49:50 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/11/30 15:54:29 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char c, va_list args)
{	
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putpointer(va_arg(args, unsigned long int));
	}
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putunsign(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_puthex(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_puthexup(va_arg(args, unsigned int));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}
// en nuestra funcion principal, declaramos un int contador y un int que 
//nos dara el numero de caracteres que imprimimos.
// va_list recibe los argumentos de la funcion y nos permite acceder a ellos.
// va_start inicializa la lista de argumentos.
// va_arg devuelve el siguiente argumento de la lista.
// va_end termina la lista de argumentos.

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		c;

	if (!str)
		return (0);
	va_start(args, str);
	count = 0;
	c = 0;
	while (str[c])
	{
		if (str[c] == '%')
		{	
			c++;
			count += ft_type(str[c], args);
		}
		else
		{
			count += ft_putchar(str[c]);
		}
		c++;
	}
	va_end(args);
	return (count);
}

// en ft_type reconocemos el tipo de argumento que recibimos
// y lo imprimimos
// si el argumento es un char, imprimimos el char.
// si el argumento es un string, imprimimos el string.
