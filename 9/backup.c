#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "mnt/content.txt";
    const char *backup_filename = "bcontent.txt";

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open the file %s\n", filename);
        return 1;
    }

    FILE *backup_file = fopen(backup_filename, "w");
    if (!backup_file) {
        printf("Failed to open the file %s\n", backup_filename);
        fclose(file);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        fputs(buffer, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    printf("Success\n");

    return 0;
}
