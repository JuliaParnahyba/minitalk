/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:37:55 by jparnahy          #+#    #+#             */
/*   Updated: 2024/03/13 20:46:53 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	back_sig(int type_sig)
{
	static int		count = 0;
	static char	c = 0;

	if (type_sig == SIGUSR1)
		c |= (0 << count);
	else if (type_sig == SIGUSR2)
		c |= (1 << count);
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction sa;
	sa.sa_handler = &back_sig;
	
	ft_printf("%i\n", getpid());

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
	return (0);
}
