#include <stdio.h>
#include <stdlib.h>

void over100(int* num);
int retVal = 0;
int baseNum[] = {4 ,3 ,3 ,5 ,4 ,4 ,3 ,5 ,5 ,4 ,3 ,6 ,6 ,8 ,8 ,7 ,7 ,9 ,8 ,8};
int tensNum[] = {6, 6 ,5 ,5 ,5 ,7 ,6 ,6};
int commaNum[] = {7, 8, 7, 7};

int main(int argc, char ** argv) {
	int num = atoi(argv[1]);
	int actual = num;
	if(num < 0 || num > 1000000000){
		return 1;
	}
	if(num == 1000000000) {retVal += (baseNum[1]+commaNum[3]); goto finished;}
	if(num == 0) {retVal += baseNum[0]; goto finished;}
	//11,618,808
	if(num > 1000000){
		int temp = num;
		retVal += commaNum[2];
		temp /= 1000000;
		over100(&temp);
		num = num - (temp * 1000000);
		if(num > 1000){
			temp = num;
			retVal += commaNum[1];
			temp /= 1000;
			num = num - (temp*1000);
			over100(&temp);
		} else {
			over100(&num);
		}
	}
	if(num > 1000) {
		int temp = num;
		retVal += commaNum[1];
		temp /= 1000;
		num = num - (temp * 1000);
		over100(&num);
	} else {
		over100(&num);
	}
	finished: printf("%d takes %d letters\n", actual, retVal);
	return 0;
}

void over100(int* num){
	if(*num > 100){
		retVal += commaNum[0];
		int temp02 = *num;
		temp02 /= 100;
		retVal += baseNum[temp02];
		*num = *num - (temp02 * 100);
		if(*num >= 20){
			int temp03 = *num;
			temp03 /= 10;
			retVal += tensNum[temp03 - 2];
			*num = *num - (temp03 * 10);
			retVal += baseNum[*num];
		} else {
			retVal += baseNum[*num];
		}
	} else {
		if(*num >= 20){
			int temp03 = *num;
			temp03 /= 10;
			retVal += tensNum[temp03 - 2];
			*num = *num - (temp03 * 10);
			retVal += baseNum[*num];
		} else {
			retVal += baseNum[*num];
		}
	}
}
