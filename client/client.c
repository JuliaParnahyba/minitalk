#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_back(int n)
{
	printf("mensagem recebida\n");
	exit(0);
}

int main(int c, char **v)
{
	signal(SIGUSR2, sig_back);
	if (c == 2)
	{
		sig_back(1);
		int server_id = atoi(v[1]);
		printf("%i\n", server_id);
		kill(server_id, SIGUSR2);
	}
	else 
		printf("falta algo, descubra!\n");
	return (0);
}
