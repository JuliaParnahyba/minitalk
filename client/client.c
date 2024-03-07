#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_msg(int n)
{
	printf("mensagem recebida\n\n");
}

int main(int c, char **v)
{
	if (c == 2)
	{
		int n = 10;
		int server_id = atoi(v[1]);
		printf("PID server: [%i]\n\n", server_id);

		signal(SIGUSR1, sig_msg);
		while (n > 0)
		{
			if (n % 2 == 0)
				kill(server_id, SIGUSR1);
			else
				kill(server_id, SIGUSR2);
			n--;
			usleep(600);
		}
	}
	else 
		printf("falta algo, descubra!\n");
	return (0);
}
