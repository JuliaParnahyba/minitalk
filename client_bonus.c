/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:47:04 by jparnahy          #+#    #+#             */
/*   Updated: 2024/03/16 17:49:18 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/minilib.h"

void	char_by_char(int c, int id)
{
	int	count;
	int	bit;

	count = 0;
	while (count < 8)
	{
		bit = (c >> count) & 1;
		if (bit == 0)
			kill(id, SIGUSR1);
		else if (bit == 1)
			kill(id, SIGUSR2);
		usleep(600);
		count++;
	}
}

void	back_msg(int n)
{
	(void) n;
	
	ft_printf("\n-----------------------------------");
	ft_printf("\n-- message received successfully --");
	ft_printf("\n-----------------------------------\n");
}

int	main(int c, char **v)
{
	if (c == 3)
	{
		char	*str;
		int		i;
		int		server_id;

		signal(SIGUSR1, back_msg);

		str = v[2];
		i = 0;
		server_id = ft_atoi(v[1]);

		while (str[i])
		{
			char_by_char(str[i], server_id);
			i++;
		}
		char_by_char(str[i], server_id);
	}
	else
		printf("./client [PID] [MSG]");
	ft_printf("\n");
	return (0);
}