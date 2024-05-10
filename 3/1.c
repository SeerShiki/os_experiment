#include <stdio.h>
#include <unistd.h>

int var = 122;

int main()
{
    printf("Target Process PID: %d\n", getpid());
    printf("Initial target_var value: %d\n", var);
    printf("Initial target_var IP: %p\n", (void *)&var);
    sleep(60);
    printf("Final target_var value: %d\n", var);
    return 0;
}
