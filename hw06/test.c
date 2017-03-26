#include <stdio.h>
#include <limits.h>

int main(int argc, char ** argv){
    float big=1e20;
    float little=-1e20;
    float pi=3.14;
    float y = (big + little)+pi;
    float z = big + (little + pi);
    float x =  (little + pi);
    printf("y == %f\n",y);
    printf("(little + pi) == %f\n", x);
    printf("little == %f", little);
    printf("z == %f\n",z);
    if (y==z) printf("This is an example of the associative property.\n");
    else printf("This is a counter-example.. the associative property does not hold!\n");
}
