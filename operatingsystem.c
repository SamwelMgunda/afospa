#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main() {
    printf("=== OS Services Demo ===\n\n");
    
    // 1. Process Information
    printf("1. Process Information:\n");
    printf("   Process ID (PID): %d\n", getpid());
    printf("   Parent PID (PPID): %d\n", getppid());
    printf("   User ID (UID): %d\n", getuid());
    printf("\n");
    
    // 2. File Operations
    printf("2. File Operations:\n");
    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
    if (fd != -1) {
        write(fd, "Hello from OS!\n", 15);
        close(fd);
        printf("   File created and written successfully\n");
    }
    printf("\n");
    
    // 3. System Time
    printf("3. System Time:\n");
    time_t now = time(NULL);
    printf("   Current Time: %s", ctime(&now));
    printf("\n");
    
    // 4. Current Directory
    printf("4. Current Directory:\n");
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("   Working Directory: %s\n", cwd);
    }
    printf("\n");
    
    printf("=== Demo Complete ===\n");
    return 0;
}