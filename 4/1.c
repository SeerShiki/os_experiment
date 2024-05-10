#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void event_handler(int signum, siginfo_t *info, void *ptr) {
    printf("dealing with the signal from process %d\n", info->si_pid);
}

int main()
{
    struct sigaction sa;
    sa.sa_sigaction = event_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);

    pid_t pid = fork();
//  printf("%d\n",getpid());
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("child progress: %d\n",getpid());
        pid_t parent_pid = getppid();
        kill(parent_pid, SIGUSR1);
    }
    else {
        printf("parent progress: %d\n",getpid());
        wait(NULL);
    }

    return 0;
}
