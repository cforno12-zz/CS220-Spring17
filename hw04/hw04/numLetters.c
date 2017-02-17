#include <stdio.h>
#include <stdlib.h>

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
	int temp = num;
	int numArray[10];
	int i;
	int size = 0; //the size of the numArray.
	for (i = 0; i < 10; i++) {
		if(temp != 0){
			numArray[i] = temp % 10;
		 	temp /= 10;
		} else {
			size = i;
			break;
		}
	}
	// words after 20 is just repeated
	int baseNum[] = {4 ,3 ,3 ,5 ,4 ,4 ,3 ,5 ,5 ,4 ,3 ,6 ,6 ,8 ,8 ,7 ,7 ,9 ,8 ,7 ,6};
	//size 21
	//starts with 30 ends with 90.
	// 30>0 -- 40>1 -- 50>2 -- 60>3 -- 70>4 -- 80>5 -- 90>6
	// i+3 to get the number.
	int tensNum[] = {6 ,6 ,5 ,5 ,7 ,6 ,5};
	//size 7
	//hundred, thousand, million, billion
	int commaNum[] = {7, 8, 7, 7};
	//size 4
	int retVal = 0;
	//base cases
	if(num == 1000000000) {retVal += (baseNum[1]+commaNum[3]); goto finished;}
	if(num == 0) {retVal += baseNum[0]; goto finished;}
	//doing the millions...
	if(num > 1000000){
		int temp = num;
		int subtract = 0;
		retVal += commaNum[2];
		temp /= 1000000;
		subtract = temp;
		if(temp > 100){
			retVal += commaNum[0];
			temp /= 10;
		}
		if(temp >= 30){
			int temp02 = temp;
			temp02 /= 10;
			retVal += tensNum[temp02 + 3];
			temp = temp - (temp02 * 10);
			retVal += baseNum[temp];
		} else{
			retVal += baseNum[temp];
		}
		num = num - (subtract * 1000000);
	}
	if(num > 1000) {
		int temp = num;
		int subtract = 0;
		retVal += commaNum[1];
		temp /= 1000;
		subtract = temp;
		if(temp > 100){
			retVal += commaNum[0];
			temp /= 10;
		}
		if(temp >= 30){
			int temp02 = temp;
			temp02 /= 10;
			retVal += tensNum[temp02 + 3];
			temp = temp - (temp02 * 10);
			retVal += baseNum[temp];
		} else {
			retVal += baseNum[temp];
		}
		num = num - (subtract * 1000);
	}
	if(num > 100){
		int temp = num;
		int subtract = 0;
		retVal += commaNum[0];
		temp /= 10;
		if(temp >= 30){
			printf("so far so good.\n");
			int temp02 = temp;
			temp02 /= 10;
			retVal += tensNum[temp02 + 3];
			temp = temp - (temp02 * 10);
			retVal += baseNum[temp];
		} else {
			retVal += baseNum[temp];
		}
		num = num - (subtract * 100);
	}
	if(num >= 30){
		int temp02 = num;
		temp02 /= 10;
		retVal += tensNum[temp02 + 3];
		num = num - (temp02 * 10);
		retVal += baseNum[num];
	} else {
		retVal += baseNum[num];
	}
	finished: printf("%d takes %d letters\n", num, retVal);
	return 0;
}
