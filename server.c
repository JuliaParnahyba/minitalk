/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:37:55 by jparnahy          #+#    #+#             */
/*   Updated: 2024/03/29 17:53:41 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/minilib.h"

void	back_sig(int type_sig)
{
	static char	c = 0;
	static int	count = 0;

	if (type_sig == SIGUSR1)
		c |= (0 << count);
	else if (type_sig == SIGUSR2)
		c |= (1 << count);
	count++;
	if (count == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			printf("\n\n");
		count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &back_sig;
	ft_printf("\n*-------------------------------------------------*");
        ft_printf("\n*-              WELLCOME TO MINITALK             -*");
        ft_printf("\n*-  /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/  -*");
        ft_printf("\n*-                               Mandatory Part  -*");
        ft_printf("\n*-------------------------------------------------*");
        ft_printf("\n\nProcess Id: [%i]\n", getpid());
        ft_printf("\nMessege sent by client:\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
