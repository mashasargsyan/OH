#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define SHM_NAME "/myshm"
#define SIZE 1024

int main() {
    int fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (fd == -1)
    {
	    perror("shm_open"); return 1; 
    }

    char *mem = mmap(NULL, SIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (mem == MAP_FAILED)
    {
	    perror("mmap"); return 1; 
    }

    printf("Reader started...\n");

    while (1) {
        if (strcmp(mem, "DONE") == 0)
            break;

        printf("Reader sees: %s\n", mem);
        sleep(1);
    }

    munmap(mem, SIZE);
    close(fd);

    shm_unlink(SHM_NAME);

    return 0;
}


