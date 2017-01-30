#include <stdio.h>
#include <string.h>

//If you are calling a function before it is defined, declare it beforehand.
int fib(int n);
int diffSq(int a, int b);

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Please invoke as %s <input-ID>\n",argv[0]);
		printf("  %s will then open a file called <input-ID>.txt,\n",argv[0]);
		printf("  perform the requested operations, and write the results to\n");
		printf("  a file called <input-ID>_results.txt\n");
		return 1;
	}

	char inFileName[100] = {'\0'};
	strcat(inFileName,argv[1]);
	strcat(inFileName,".txt");
	char outFileName[100]={'\0'};
	strcat(outFileName,argv[1]);
	strcat(outFileName,"_results.txt");

	FILE *inFile=NULL;
	inFile=fopen(inFileName,"r");
	if (inFile==NULL) {
		printf("Unable to open input file %s... quitting.\n",inFileName);
		return 1;
	}

	FILE *outFile=NULL;
	outFile=fopen(outFileName,"w");
	if (outFile==NULL) {
		printf("Unable to open output file %s... quitting.\n",outFileName);
		fclose(inFile);
		return 1;
	}

	int a;
	int b;
	int result;
	while(!feof(inFile)) {
		if (1==fscanf(inFile," fib %d ",&a)) {
			/*
			* When I comment out the function declarations above the lines 46 and 50 have given me an error
			* warning: implicit declaration of function 'fib' is invalid in C99
			* warning: implicit declaration of function 'diffSq' is invalid in C99
			* ------------------------------------------------------------------ (after research)
			* It seems that you have to declare the function before you can use it.
			* vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
			* But how does the complier know to use the function after it is called?
			* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			*/
			result=fib(a);
			fprintf(outFile,"fib(%d) = %d\n",a,result);
		}
		else if (2==fscanf(inFile," diffSq %d %d ",&a,&b)) {
			result = diffSq(a,b);
			fprintf(outFile,"diffSq(%d,%d) = %d\n",a,b,result);
		} else {
			char unrecognized[256];
			fscanf(inFile," %256s",unrecognized);
			printf("The following word from the input file is not recognized: %s\n",unrecognized);
		}
	}
	fclose(inFile);
	fclose(outFile);
	return 0;
}

int fib(int n) {
	/* Write the code to return the nth fibonacci number here */
	int retVal = 0;
	if(n == 0){
		retVal = 0;
	} else if (n == 1) {
		retVal = 1;
	} else {
		retVal = (fib(n-1) + fib(n-2));
	}
	return retVal;
}

int diffSq(int a, int b) {
	/* Write the code to return the difference between the square of a and square of b here */
	a = a * a;
	b = b * b;
	return a - b;
}
