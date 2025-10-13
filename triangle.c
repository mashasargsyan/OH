#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
        if (argc != 4)
                return 1;
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        int c = atoi(argv[3]);
        double s = (a + b + c) / 2;
        double area = sqrt(s*(s-a)*(s-b)*(s-c));
        printf("The area of a triangle with edges %d, %d and %d is %f\n", a, b, c, area);
        return 0;
}
