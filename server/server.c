#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void back_sig(int type_sig, siginfo_t *info, void *context)
{
	(void) context;

	static int count = 0;
	
	if (type_sig == SIGUSR1)
		printf("NO SIG1\n\n");
	if (type_sig == SIGUSR2)
		printf("NO SIG2\n\n");
	count++;
	if (count == 10)
		kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction sa;
	sa.sa_sigaction = &back_sig;
	sa.sa_flags = SA_SIGINFO;

	printf("\n ----------- ***** ----------\n\n");
	printf("QUE COMECEM OS JOGOS!\n");
	printf("%i\n", getpid());
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while(1);
	return (0);
}
