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
    int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (fd == -1) 
    {
	perror("shm_open"); return 1; 
    }

    ftruncate(fd, SIZE);

    char *mem = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mem == MAP_FAILED)
    { 
	 perror("mmap"); return 1;
    } 

    printf("Writer started...\n");

    for (int i = 0; i < 5; i++) {
        sprintf(mem, "Message #%d", i);
        printf("Writer wrote: %s\n", mem);
        sleep(2);
    }

    strcpy(mem, "DONE");

    munmap(mem, SIZE);
    close(fd);

    return 0;
}


