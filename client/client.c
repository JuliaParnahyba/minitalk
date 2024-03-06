#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_msg(void)
{
	printf("mensagem recebida\n\n");
}
/*
void sig_back(int sig)
{
}
*/
int main(int c, char **v)
{
	if (c == 2)
	{
		sig_msg();

		int n = 10;
		int server_id = atoi(v[1]);
		printf("PID server: [%i]\n\n", server_id);

		while (n > 0)
		{
			printf("chegou aqui\n");
			signal(SIGUSR1, server_id);
			printf("passou do kill\n");
			n--;
		}
	}
	else 
		printf("falta algo, descubra!\n");
	return (0);
}
