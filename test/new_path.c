#include<stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stddef.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{
    char *program_directory = "/home/hm/os_experiment/1";
    char *existing_path = getenv("PATH");
    char new_path[1024];
    snprintf(new_path, sizeof(new_path), "%s:%s", existing_path, program_directory);
    printf("%s\n",new_path);
//    setenv("PATH", new_path, 1);
    printf("%s\n",getenv("PATH"));

    system("myshell3");

    return 0;
}

///home/hm/anaconda3/bin:/home/hm/anaconda3/condabin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
