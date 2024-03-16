/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:37:55 by jparnahy          #+#    #+#             */
/*   Updated: 2024/03/16 19:12:36 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/minilib.h"

void	back_sig_bonus(int type_sig, siginfo_t *info, void *context)
{
	static int	count = 0;
	static char	c = 0;

	if (type_sig == SIGUSR1)
		c |= (0 << count);
	else if (type_sig == SIGUSR2)
		c |= (1 << count);
	count++;
	if (count == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &back_sig_bonus;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("\n*--------------------------------------------------*");
	ft_printf("\n*--------------------------------------------------*");
	ft_printf("\n*-          WELLCOME TO MINITALK PROJECT          -*");
	ft_printf("\n*-                                                -*");
	ft_printf("\n*-  /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/**/*/*/*/  -*");
	ft_printf("\n*-                                                -*");
	ft_printf("\n*-                            by: Julia Parnahyba -*");
	ft_printf("\n*--------------------------------------------------*");
	ft_printf("\n*--------------------------------------------------*");
	ft_printf("\nProcess Id: [%i]\n", getpid());
	ft_printf("\nMessege sent by client:\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
