#include <stdio.h>
#include <math.h>

char fact_char(char n);
/* Other function declarations for short, int, long, float, and double factorials go here */

int main(int argc, char **argv) {

	char i_char;
	for(i_char=1; ; i_char++) {
		char r_char;
		r_char = fact_char(i_char);
		if (i_char >=2 && 0 != r_char%2 ) break; // Every number >2! should be divisible by 2
		if (i_char >=5 && 0 != r_char%10) break; // Every number >5! should be divisible by 10
		printf("%d! = %d\n",i_char,r_char);
	}
	printf("%d! does not fit in a char variable\n",i_char);

	/* Repeat the above loop for other data types */
	return 0;
}

char fact_char(char n) {
	if (n<3) return n;
	return n*fact_char(n-1);
}

/* Define factorial functions for short, int, long, float, and double here */