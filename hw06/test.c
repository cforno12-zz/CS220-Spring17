#include <stdio.h>

int main(int argc, char ** argv){
    int x = -5;
    int y = (x | (-1-x));

    printf("Size of int is: %lu\n", sizeof(y));

    if (y == -1){
        printf("How did you know that?\n");
    } else {
        printf("Special value of x\n!");
    }
}
