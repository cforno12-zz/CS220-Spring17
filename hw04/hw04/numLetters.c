#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	/*
	The program need to calculate the number of letters required to write the
	number using English words.
	*/
	int num = atoi(argv[1]);
	int actual = num;
	//if the number is inputted is less than zero or greater than a billion
	//the program is not equipped to handle those types of numers
	if(num < 0 || num > 1000000000){
		return 1;
	}
	// words after 20 is just repeated
	int baseNum[] = {4 ,3 ,3 ,5 ,4 ,4 ,3 ,5 ,5 ,4 ,3 ,6 ,6 ,8 ,8 ,7 ,7 ,9 ,8 ,8};
	//size 21
	//starts with 30 ends with 90.
	// 30>0 -- 40>1 -- 50>2 -- 60>3 -- 70>4 -- 80>5 -- 90>6
	// i+3 to get the number.
	int tensNum[] = {6, 6 ,6 ,5 ,5 ,7 ,6 ,6};
	//size 7
	//hundred, thousand, million, billion
	int commaNum[] = {7, 8, 7, 7};
	//size 4
	int retVal = 0;
	//base cases
	if(num == 1000000000) {retVal += (baseNum[1]+commaNum[3]); goto finished;}
	if(num == 0) {retVal += baseNum[0]; goto finished;}
	//11,618,808
	//doing the millions...
	if(num > 1000000){
		int temp = num;
		retVal += commaNum[2];
		temp /= 1000000;
		num = num - (temp * 1000000);
		if(temp > 100){
			retVal += commaNum[0];
			int temp02 = temp;
			temp /= 100;
			retVal += baseNum[temp];
			temp = temp - (temp * 100);
			if(temp >= 20){
				int temp03 = temp;
				temp03 /= 10;
				retVal += tensNum[temp03 - 2];
				temp = temp - (temp03 * 10);
				retVal += baseNum[temp];
			} else {
				retVal += baseNum[temp];
			}
		} else {
			if(temp >= 20){
				int temp03 = temp;
				temp03 /= 10;
				retVal += tensNum[temp03 - 2];
				temp = temp - (temp03 * 10);
				retVal += baseNum[temp];
			} else {
				retVal += baseNum[temp];
			}
		}
	}
	if(num > 1000) {
		int temp = num;
		retVal += commaNum[1];
		temp /= 1000;
		num = num - (temp * 1000);
		if(temp > 100){
			retVal += commaNum[0];
		}
	}

	if(num > 100){
		retVal += commaNum[0];
		int temp02 = num;
		num /= 100;
		retVal += baseNum[num];
		num = num - (num * 100);
		if(num >= 20){
			int temp03 = num;
			temp03 /= 10;
			retVal += tensNum[temp03 - 2];
			num = num - (temp03 * 10);
			retVal += baseNum[num];
		} else {
			retVal += baseNum[num];
		}
	} else {
		if(num >= 20){
			int temp03 = num;
			temp03 /= 10;
			retVal += tensNum[temp03 - 2];
			num = num - (temp03 * 10);
			retVal += baseNum[num];
		} else {
			retVal += baseNum[num];
		}
	}


	finished: printf("%d takes %d letters\n", actual, retVal);
	return 0;
}

void over100(int* n){

}
