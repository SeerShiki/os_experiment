#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 256

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Error");
        return 1;
    }

    pid_t target_pid = atoi(argv[1]);
    int new_value = atoi(argv[2]);

    char mem_path[SIZE];
    sprintf(mem_path, "/proc/%d/mem", target_pid);
    int mem_fd = open(mem_path, O_RDWR);
    if (mem_fd == -1) {
        perror("Failed to open mem file");
        return 1;
    }

    off_t var_address =  (off_t)strtol(argv[3], NULL, 16);

    if (lseek(mem_fd, var_address, SEEK_SET) == -1) {
        perror("Failed to seek mem file");
        close(mem_fd);
        return 1;
    }

    if (write(mem_fd, &new_value, sizeof(new_value)) == -1) {
        perror("Failed to write to mem file");
        close(mem_fd);
        return 1;
    }

    close(mem_fd);
    printf("Successfully write in the new value in process %d\n", target_pid);

    return 0;
}
