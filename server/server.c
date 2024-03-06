#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


void hello(int n)
{
	static int count = 1;
	printf("value of count: %i\n", count);
	count++;
}

int main(void)
{
	printf("%i\n", getpid());
	hello(1);
	signal(SIGUSR1, hello);
	while(1);

	printf("chegou aqui\n");
	
	return (0);
}
