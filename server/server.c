#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


void hello(int n)
{
	write(1, "ok\n", 3);
	exit (3);
}

int main(void)
{
	printf("%i\n", getpid());
//	signal(SIGUSR1, hello);
	signal(SIGINT, hello);
	while(1);
//	exit(5);
	
	hello(1);

	printf("chegou aqui\n");
	
	return (0);
}
