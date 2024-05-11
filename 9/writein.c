#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *backup_filename = "bcontent.txt";
    const char *mount_path = "mnt/content.txt";

    FILE *backup_file = fopen(backup_filename, "r");
    if (!backup_file) {
        printf("Failed to open the backup file: %s\n", backup_filename);
        return 1;
    }

    FILE *mount_file = fopen(mount_path, "w");
    if (!mount_file) {
        printf("Failed to open the file in mnt: %s\n", backup_filename);
        fclose(backup_file);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), backup_file)) {
        fputs(buffer, mount_file);
    }

    fclose(backup_file);
    fclose(mount_file);

    printf("Success\n");

    return 0;
}
