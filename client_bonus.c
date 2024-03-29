/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:47:04 by jparnahy          #+#    #+#             */
/*   Updated: 2024/03/29 17:51:16 by jparnahy         ###   ########.fr       */
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

void	back_msg(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("\n-----------------------------------");
		ft_printf("\n-- message received successfully --");
		ft_printf("\n-----------------------------------\n\n");
	}
}

int	main(int c, char **v)
{
	char	*str;
	int		i;
	int		server_id;

	if (c == 3)
	{
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
	{
		printf("ERROR :: Use the correct pattern ::\n\n");
		printf("< ./client_bonus [SERVER_PID] [MESSAGE] >\n");
	}
	return (0);
}
