#include <stdio.h>

int main(int argc, char ** argv) {
	/*
	The program need to calculate the number of letters required to write the
	number using English words.
	*/

	int num = atoi(argv[1]);
	//if the number is inputted is less than zero or greater than a billion
	//the program is not equipped to handle those types of numers
	if(num < 0 || num > 1000000000){
		return 1;
	}
	//numArray is an array which contains all the digits in the inputted number
	//each in its own index.
	int numArray[10];
	int i;
	int size = 0; //the size of the numArray.
	for (i = 0; i < 10; i++) {
		if(num != 0){
			numArray[i] = num % 10;
		 	num /= 10;
		} else {
			size = i
			break;
		}
	}
	// words after 20 is just repeated
	int baseNum[] = {4 ,3 ,3 ,5 ,4 ,4 ,3 ,5 ,5 ,4 ,3 ,6 ,6 ,8 ,8 ,7 ,7 ,9 ,8 ,7 ,6};
	//size 21
	//starts with 30
	int tensNum[] = {6 ,6 ,5 ,5 ,7 ,6 ,5};
	//size 7
	//hundred, thousand, million, billion
	int commaNum[] = {7, 8, 7, 7};
	//size 4
	int retVal = 0;
	if(num == 1000000000 ){
		retVal += commaNum[3];
	}
	if()


	//printf("%d takes %d letters\n", num, result);
	return 0;
}
