/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:27:29 by jparnahy          #+#    #+#             */
/*   Updated: 2024/03/18 18:45:19 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	printf_type(const char *print, va_list var)
{
	unsigned int	res;

	res = 0;
	if (*print == 'c')
		res += printf_putchr(va_arg(var, int));
	else if (*print == 's')
		res += printf_putstr(va_arg(var, char *));
	else if (*print == 'p')
		res += printf_ptr(va_arg(var, unsigned long int));
	else if (*print == 'd')
		res += printf_putnbr(va_arg(var, int));
	else if (*print == 'i')
		res += printf_putnbr(va_arg(var, int));
	else if (*print == 'u')
		res += printf_unsig_putnbr(va_arg(var, unsigned int));
	else if (*print == 'x')
		res += printf_hexa(va_arg(var, unsigned int), 1);
	else if (*print == 'X')
		res += printf_hexa(va_arg(var, unsigned int), 2);
	else if (*print == '%')
		res += printf_putchr('%');
	return (res);
}

int	ft_printf(const char *phrase, ...)
{
	unsigned int	res;
	va_list			var;

	if (!phrase)
		return (0);
	res = 0;
	va_start(var, phrase);
	while (*phrase != '\0')
	{
		if (*phrase == '%')
		{
			phrase++;
			res += printf_type(phrase, var);
		}
		else
			res += printf_putchr(*phrase);
		phrase++;
	}
	va_end(var);
	return (res);
}
