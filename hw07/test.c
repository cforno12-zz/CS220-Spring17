#include <stdio.h>
#include <netinet/in.h>

int main(int argc, char ** argv){
    int x = 16843009;

    int y = htonl(x);
    printf("Values:x == %X\n",x);
    printf("Little endian: %X\n",y);
}
