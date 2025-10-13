#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
        if (argc != 3)
                return 1;
        printf("The area of rectangle with edges %s and %s is %d\n", argv[1], argv[2], atoi(argv[1]) * atoi(argv[2]));
        execl("/home/anpordzanq/lessons/triangle", "triangle", "3", "4", "5", NULL);
       
        return 0;
}
