//includes slots.h (an interface)
#include "slots.h"
#include <stdio.h>

int leastLikely(int binArr []);

int main(int argc, char ** argv) {
	int bin;
	int index = 0;
	int bins [100];
	for (int i = 0; i < 100; i++) {
		bins[i] = 0;
	}
	initSlots();
	//as long as there are more bin numbers on the order for the kit....continunes onto the while loop
	//bin is initialized with the scanf function
	while(1 == scanf("%d",&bin)) {
		bins[bin]++;
		// this line of code is counting all of the widgets in the order.
		if (-1==findSlot(bin)) {
			// getBin index should have a number between 0-3
			//make the program choose a bin to return 'intelligently'
			//TODO: Send bck the bin that is least likely to be needed again in the near future
			getBin(bin,index);
			for (int i = 0; i < 8; i++) {
				printf("#%i:%i ",i,bins[i]);
			}
			printf("%i\n", leastLikely(bins));
			if(index < 3){
				index++;
			} else {
				//set the index to the least likely number to appear in the future
				//leastLikely(bins);
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
int leastLikely(int binArr []){
	int index = 0;
	int value = 0;
	for (int i = 0; i < 100; i++) {
		if(binArr[i] != 0 && binArr[i] >= value){
			value = binArr[i];
			index = i;
		}
	}
	return index;
}
