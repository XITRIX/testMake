#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

#define SIG SIGUSR1

static void handler(int sig, siginfo_t *si, void *uc){
	printf("Caused signal %d, sending PID: %ld\n", sig, (long)si->si_pid);
}

int main(){
	sigset_t mask;
	struct sigaction sa;
	printf("Establishing handler for signal %d\n", SIG);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if(sigaction(SIG, &sa, NULL) == -1){
		perror("signation");
		return 1;
	}

	pause();
	return 0;
}