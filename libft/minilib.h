/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:11:23 by jparnahy          #+#    #+#             */
/*   Updated: 2024/03/18 18:45:50 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_H
# define MINILIB_H

/*  -*-*-*-*-*-*-* C LIBRARIES USED *-*-*-*-*-*-  */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

/*  -*-*-*-*-*-*-* FUNCTIONS PROTOTYPES  *-*-*-*-*-*-  */

int	ft_atoi(const char *nptr);
int	ft_printf(const char *print, ...);

/*  -*-*-*-*-*-*-* AUXILIARY FUNCTIONS PROTOTYPES  *-*-*-*-*-*-  */

int	printf_putchr(char chr);
int	printf_putstr(char *chr);
int	printf_putnbr(long int nbr);
int	printf_unsig_putnbr(unsigned int nbr);
int	printf_hexa(unsigned long int n, int type);
int	printf_ptr(unsigned long int n);

#endif
