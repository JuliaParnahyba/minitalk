/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:37:07 by jparnahy          #+#    #+#             */
/*   Updated: 2024/03/18 18:52:42 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	printf_putchr(char chr)
{
	write(1, &chr, 1);
	return (1);
}

int	printf_putstr(char *chr)
{
	int	len;

	if (chr == NULL)
		chr = "(null)";
	len = 0;
	while (chr[len])
		printf_putchr(chr[len++]);
	return (len);
}
