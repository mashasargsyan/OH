#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        printf("Can't open the file\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int line_number = 0;

    while ((read = getline(&line, &len, file)) != -1) {
        line_number++;

        char operation[10];
        int a, b, r;

        int items = sscanf(line, "%s %d %d", operation, &a, &b);
        if (items != 3) {
            printf("Error on line %d:\n", line_number);
            break; 
        }

        if (strcmp(operation, "add") == 0) {
            r = a + b;
        }
        else if (strcmp(operation, "sub") == 0) {
            r = a - b;
        }
        else if (strcmp(operation, "mul") == 0) {
            r = a * b;
        }
        else if (strcmp(operation, "div") == 0) {
            r = a / b;
        }
        else {
            printf("Unknown operation\n");
            break; 
        }

        printf("%s %d %d = %d\n", operation, a, b, r);
    }

    free(line);
    fclose(file);
    return 0;
}

