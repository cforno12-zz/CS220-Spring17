#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    int order[25];
    int i;
    for (i = 0; i < 25; i++) {
        int ind = rand()%(i+1);
        if(ind == i){
            order[i] = rand()&99;
        } else {
            order[i] = order[ind];
        }
    }
    for (i = 0; i < 25; i++) {
        printf("%i ", order[i]);
    }
    printf("\n");
}
