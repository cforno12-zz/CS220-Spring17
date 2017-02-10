#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAXROWS 64
#define MAXCOLS 64
#define MAXRAND 100

//Global variables
int matA[MAXROWS][MAXCOLS];
int matB[MAXROWS][MAXCOLS];
int matC[MAXROWS][MAXCOLS];

/*
* Purpose of this program is to provide a way to set the values of matA and matB
* and then calculate the value of matC using matrix multiplication, where
* matC = matA x matB.
*/


//Three ways of setting matrixes A and B. The functions listed below.
void setA_ID(int rows,int cols); // Set matA to rows x cols ID matrix
void setB_ID(int rows,int cols); // Set matB to rows x cols ID matrix
void setA_Rand(int rows,int cols); // Set matA to rows x cols random #
void setB_Rand(int rows,int cols); // Set matB to rows x cols random #
void setA_Stdin(int rows,int cols); // Set matA to numbers from stdin
void setB_Stdin(int rows,int cols); // Set matB to numbers from stdin
void setC_Prod(int ra,int carb, int cb); // Set matC to matA x matB
int multHelper(int a, int ab, int b);

void printMatrix(char name[], int row, int cols,
	int matrix[MAXROWS][MAXCOLS]); // Print the matrix specified

int main(int argc, char **argv) {
	if (argc<6)  {
		printf("Invoke as %s <R/I/S> <arows> <acols> <R/I/S> <bcols>\n",argv[0]);
		return 1;
	}

	int arows=atoi(argv[2]);
	int acols=atoi(argv[3]);
	int bcols=atoi(argv[5]);

	if (arows==0 || arows>MAXROWS) {
		printf("Choose 2nd argument (arows) between 1 and %d (was %d)\n",
			MAXROWS,arows);
		return 1;
	}

	if (acols==0 || acols>((MAXROWS<MAXCOLS)?MAXROWS:MAXCOLS)) {
		printf("Choose 3rd argument (acols) between 1 and %d (was %d)\n",
			(MAXROWS<MAXCOLS)?MAXROWS:MAXCOLS ,acols);
		return 1;
	}

	if (bcols==0 || bcols>MAXCOLS) {
		printf("Choose 5th argument (bcols) between 1 and %d (was %d)\n",
			MAXCOLS,bcols);
		return 1;
	}

	time_t t;
	srand((unsigned) time(&t)); /* Seeds random number generator with the time */

	switch(argv[1][0]) {
		case 'R' : setA_Rand(arows,acols); break;
		case 'I' : setA_ID(arows,acols); break;
		case 'S' : setA_Stdin(arows,acols); break;
		default :
			printf("Choose first argument of either R for random or I for identity or S for stdin (was %c)\n",
				argv[1][0]);
			return 1;
	}

	switch(argv[4][0]) {
		case 'R' : setB_Rand(acols,bcols); break;
		case 'I' : setB_ID(acols,bcols); break;
		case 'S' : setB_Stdin(acols,bcols); break;
		default :
			printf("Choose 4th argument of either R for random or I for identity or S for stdin (was %c)\n",
				argv[4][0]);
			return 1;
	}
	setC_Prod(arows,acols,bcols);
	return 0;
}

/* -------------------------------------------------------------------------------------------
	Sub-functions go here
----------------------------------------------------------------------------------------------*/

void setA_ID(int rows, int cols){
	int row;
	int col;
	for(row=0;row<rows;row++){
		for(col=0;col<cols;col++){
			if(row == col){
				matA[row][col] = 1;
			} else {
				matA[row][col] = 0;
			}
		}
	}
	printMatrix("A",rows,cols,matA);
}

void setA_Rand(int rows,int cols) {
	int row;
	int col;
	for(row=0;row<rows;row++) {
		for(col=0;col<cols;col++) {
			matA[row][col]=rand()%MAXRAND;
		}
	}
	printMatrix("A",rows,cols,matA);
}

void setA_Stdin(int rows,int cols) {
	int row;
	int col;
	int nextNum;
	for(row=0;row<rows;row++) {
		for(col=0;col<cols;col++) {
			assert(1==scanf("%d ",&nextNum));
			matA[row][col]=nextNum;
		}
	}
	printMatrix("A",rows,cols,matA);
}

void setB_ID(int rows, int cols){
	int row;
	int col;
	for(row=0;row<rows;row++){
		for(col=0;col<cols;col++){
			if(row == col){
				matB[row][col] = 1;
			} else {
				matB[row][col] = 0;
			}
		}
	}
	printMatrix("B",rows,cols,matB);
}

void setB_Rand(int rows,int cols) {
	int row;
	int col;
	for(row=0;row<rows;row++) {
		for(col=0;col<cols;col++) {
			matB[row][col]=rand()%MAXRAND;
		}
	}
	printMatrix("B",rows,cols,matB);
}

void setB_Stdin(int rows,int cols) {
	int row;
	int col;
	int nextNum;
	for(row=0;row<rows;row++) {
		for(col=0;col<cols;col++) {
			assert(1==scanf("%d ",&nextNum));
			matB[row][col]=nextNum;
		}
	}
	printMatrix("B",rows,cols,matB);
}

void setC_Prod(int a,int ab, int b){
	// a == rows of A
	// ab == columns of A and rows of B
	// b == columns of B
	int sum = 0;
	int i; //init of rows of A
	int j; // init columns of b
	int k; // init of ab from parameters
	for (i = 0; i < a; i++) {
      for (j = 0; j < b; j++) {
		//accessing Cmat at this point
        for (k = 0; k < ab; k++) {
			//k is number of times the elements have to be muiltiped together
          sum += multHelper(i,k,j);
        }
        matC[i][j] = sum;
        sum = 0;
      }
    }
	printMatrix("AxB",a,b,matC);
}

int multHelper(int a, int ab, int b){
	int varA = matA[a][ab];
	int varB = matB[ab][b];
	return varA * varB;
}

void printMatrix(char name[], int rows, int cols,  int matrix[MAXROWS][MAXCOLS]) {
	assert(rows<=MAXROWS);
	assert(cols<=MAXCOLS);
	int row;
	int col;
	int mrow = rows/2;
	char prefix[256]="";
	for(col=0;col<strlen(name); col++) strcat(prefix," ");
	for(row=0;row<rows;row++) {
		if (row==mrow) printf("%s = |",name);
		else printf("%s   |",prefix);
		for (col=0;col<cols;col++) {
			printf(" %2d",matrix[row][col]);
		}
		printf(" |\n");
	}
	printf("\n");
}
