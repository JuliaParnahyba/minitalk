/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:39:29 by jparnahy          #+#    #+#             */
/*   Updated: 2024/03/13 21:03:36 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilib.h"

int     printf_ptr(unsigned long int n)
{
        int             len;

        if (!n)
                return (printf_putstr("(nil)"));
        printf_putstr("0x");
        len = 2;
        return (len + printf_hexa(n, 1));
}

int     printf_putnbr(long int nbr)
{
        char    str[10];
        int             i;
        int             len;

        len = 0;
        if (nbr == 0)
        {
                return (printf_putchr('0'));
        }
        if (nbr < 0)
        {
                nbr *= -1;
                printf_putchr('-');
                len = 1;
        }
        i = 0;
        while (nbr > 0)
        {
                str[i++] = (nbr % 10) + 48;
                nbr /= 10;
                len++;
        }
        while (--i >= 0)
                printf_putchr(str[i]);
        return (len);
}

int     printf_unsig_putnbr(unsigned int nbr)
{
        char    str[10];
        int             i;
        int             len;

        len = 0;
        i = 0;
        if (nbr == 0)
                return (printf_putchr('0'));
        while ((unsigned long int)nbr > 0)
        {
                str[i++] = (nbr % 10) + 48;
                nbr /= 10;
                len++;
        }
        while (--i >= 0)
                printf_putchr(str[i]);
        return (len);
}

int     printf_hexa(unsigned long int n, int type)
{
        char    *hexa;
        int             len;

        len = 0;
        if (type == 1)
                hexa = "0123456789abcdef";
        if (type == 2)
                hexa = "0123456789ABCDEF";
        if (n < 16)
                len = printf_putchr(hexa[n]);
        else
        {
                len += printf_hexa(n / 16, type);
                return (len + printf_hexa((n % 16), type));
        }
        return (len);
}
