#include <stdio.h>

int main(int argc, char ** argv){
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    unsigned int v = x;
    unsigned int w = y;
    int s_sum = x+y;
    unsigned int u_sum = v+w;
    if(s_sum == u_sum){
        printf("Unsigned and signed are the same\n");
    } else {
        printf("Unsigned and signed are different\n");
    }
}
