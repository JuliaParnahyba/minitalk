#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void back_sig(int type_sig, siginfo_t *info, void *context)
{
	(void) context;

	static int	count;
	static char	c;

	count = 0;
	if (type_sig == SIGUSR1) //zero
		c |= (0 << count); 
	else if (type_sig == SIGUSR2) //um
		c |= (1 << count);
	count++;
	if (count == 8)
	{
		printf("%c", c);
		count = 0;
		c = 0;
	}
}


//	kill(info->si_pid, SIGUSR1);

int main(void)
{
	struct sigaction sa;
	sa.sa_sigaction = &back_sig;
	sa.sa_flags = SA_SIGINFO;

	printf("\n ----------- ***** ----------\n\n");
	printf("%i\n", getpid());
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while(1)
		pause();
	return (0);
}
