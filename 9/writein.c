#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *backup_filename = "bcontent.txt";
    const char *mount_path = "mnt/content.txt";

    FILE *backup_file = fopen(backup_filename, "r");
    if (!backup_file) {
        perror("无法打开备份文件");
        return 1;
    }

    FILE *mount_file = fopen(mount_path, "w");
    if (!mount_file) {
        perror("无法打开挂载点文件");
        fclose(backup_file);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), backup_file)) {
        fputs(buffer, mount_file);
    }

    fclose(backup_file);
    fclose(mount_file);

    printf("文件写入挂载点完成\n");

    return 0;
}
