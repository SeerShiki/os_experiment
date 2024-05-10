#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define SIZE 1024

int main()
{
    int pipe_rw1[2],pipe_rw2[2]; //[0]:RD [1]:WR
    char buffer1[SIZE],buffer2[SIZE];
    pid_t pid;

    if (pipe(pipe_rw1) == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }
    if (pipe(pipe_rw2) == -1) {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0){
        close(pipe_rw1[0]);
        close(pipe_rw2[1]);

        printf("send a message to child process:\n");
        fgets(buffer1, SIZE, stdin);
        write(pipe_rw1[1], buffer1, sizeof(buffer1));

        read(pipe_rw2[0], buffer2, sizeof(buffer2));
        printf("received message from child process: %s", buffer2);
    }
    else{
        close(pipe_rw1[1]);
        close(pipe_rw2[0]);

        read(pipe_rw1[0], buffer1, sizeof(buffer1));
        printf("received a message from parent process: %s", buffer1);

        printf("send a message to parent process:\n");
        fgets(buffer2, SIZE, stdin);
        write(pipe_rw2[1], buffer2, sizeof(buffer2));
    }

    return 0;
}
