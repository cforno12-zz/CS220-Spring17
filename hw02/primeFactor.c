#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int nextFactor(int n);

int main(int argc, char **argv) {

	if (argc<2) {
		printf("Invoke as %s <integer>\n",argv[0]);
		return 1;
	}

	int n = atoi(argv[1]); // Convert input argument to an integer

	if (n<2) {
		printf("%s invoked with %d which is not a valid argument (<2)\n",
			argv[0],n);
		return 1;
	}

	printf(" %d = ",n);
	while(n>1) {
		int f = nextFactor(n);
		assert(f>1);
		if (n == f) break;
		printf(" %d * ",f);
		n = n / f;
	}
	printf(" %d\n",n);
	return 0;
}

int nextFactor(int n) {
	/* Insert code to return the next prime factor in n here */
	int f = 2;
	while(f > 0){
		if(n%f == 0){
			return f;
		} else {
			f++;
		}
	}
	return 1;
}

//sudo security add-trust -d -r trustRoot -p basic -p codeSign -k /Library/Keychains/System.keychain ~/Desktop/gdb_codesign.cer
