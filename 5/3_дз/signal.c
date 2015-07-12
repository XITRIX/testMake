#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

#define SIG SIGUSR1
#define SIG2 SIGQUIT

void handler(int sig, siginfo_t *si, void *uc) {
	printf("Caught signal %d, sending PID: %ld\n", sig, (long)si->si_pid);
}
void handler2(int sig, siginfo_t *si, void *uc) {
	printf("Caught signal %d, sending PID: %ld\n", sig, (long)si->si_pid);
}

int main(int argc, char *argv[]) {
	sigset_t mask;
	struct sigaction sa;
	struct sigaction sa2;

	printf("Establishing handler for signal %d and %d\n", SIG, SIG2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = handler2;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIG, &sa, NULL) == -1) {
		perror("sigaction");
		return 1;
	}

	if (sigaction(SIG2, &sa2, NULL) == -1) {
		perror("sigaction");
		return 1;
	}

	while(1);
	return 0;
}