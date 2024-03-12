#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void char_by_char(int c, int id)
{
	int	count;
	int	bit = c;

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

void sig_msg(int n)
{
	printf("mensagem recebida\n\n");
}

int main(int c, char **v)
{
	if (c == 3)
	{
		char	*str;
		int		i;
		int		server_id;
		
		signal(SIGUSR1, &sig_msg);

		str = v[2];
		i = 0;
		server_id = atoi(v[1]);

		while (str[i])
		{
			char_by_char(str[i], server_id);
			i++;
		}
		if (str[i] == '\0')
			char_by_char(str[i], server_id);
	}
	else 
		printf("./client [PID] [string]\n");
	return (0);
}
