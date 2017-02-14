#include <stdio.h>

int main(int argc, char ** argv) {
	/*
	The program need to calculate the number of letters required to write the
	number using English words.
	*/
	int num;

	scanf("%i\n", &num);

	if(num < 0 || num > 1000000000){
		return 1;
	}
	int bill = 0;
	int hundMill = 0;
	int tensMill = 0;
	int onesMill = 0;
	int hundThou = 0;
	int tensThou = 0;
	int onesThou = 0;
	int hund = 0;
	int tens = 0;
	int ones = 0;

	int numArray[] = {bill, hundMill, tensMill, onesMill, hundThou, tensThou, onesThou, hund, tens, ones};
	int temp = 0;
	while (num > 0) {
		if(num == 1000000000){
			temp = num;
			temp /= 1000000000;
			numArray[0] = temp;
			num -= temp * 1000000000;
			continue;
		}
		if(num > 100000000){
			temp = num;
			temp /= 100000000;
			numArray[1] = temp;
			num -= temp * 100000000;
			continue;
		}
		if(num > 10000000){
			temp = num;
			temp /= 10000000;
			numArray[2] = temp;
			num -= temp * 10000000;
			continue;
		}
		if(num > )
	}
	int result = 0;

	printf("%d takes %d letters\n", num, result);
	return 0;
}
