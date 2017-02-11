//includes slots.h (an interface)
#include "slots.h"
#include <stdio.h>

//global variables
int bins [100]; //array to keep track of the input of the order from the customer.

int leastLikely();

int main(int argc, char ** argv) {
	int bin;
	int index = 0;
	int least;
	int i;
	//initialize bins array to 0.
	for (i = 0; i < 100; i++) {
		bins[i] = 0;
	}
	initSlots();
	//as long as there are more bin numbers on the order for the kit....continunes onto the while loop
	//bin is initialized with the scanf function
	while(1 == scanf("%d",&bin)) {
		bins[bin]++; // this line of code is counting all of the widgets in the order.

		if (-1==findSlot(bin)) {
			// getBin index should have a number between 0-3
			//TODO: Send bck the bin that is least likely to be needed again in the near future
			getBin(bin,index);
			if(index < 3){
				index++;
			} else {
				//set the index to the least likely number to appear in the future
				least = leastLikely();
				index =findSlot(least);
			}
		}
		getWidget(bin);
	}
	/*for (int i = 0; i < 100; i++) {
		printf("%i\n", bins[i]);
	}*/
	printEarnings();
	return 0;
}
//TODO: Make a function that calculates the least likely number to be in the future
int leastLikely(){
	int index = 0;
	int value = +2147483647;
	int i;
	for (i = 0; i < 100; i++) {
		if(bins[i] != 0 && bins[i] < value){
			value = bins[i];
			index = i;
		}
	}
	return index;
}
