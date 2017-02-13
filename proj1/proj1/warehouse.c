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
	while(1 == scanf("%d",&bin)) {
		bins[bin]++;
		/*
		* The bins array is a frequency table updating every time there an order is inputted.
		*/
		//this condition checks to see if the given bin is already in the workbench
		if (-1==findSlot(bin)) {
			int first = 0;
			getBin(bin,index);
			if(index < 3 && first == 0){
				index++;
			} else {
				//printf("This bin isn't in the workbench: %i\n", bin);
				first = 1;
				for (i = 0; i < 100; i++) {
					if(bins[i]!= 0){
						//printf("%i:%i ", i,bins[i]);
					}
				}
				//printf("\n");
				//set the index to the least likely number to appear in the future
				do{
					least = leastLikely();
					index = findSlot(least);
					/*
					* if the least likely widget is returned, but is not in the workbench,
					* then go back to the frequency table and decrease the frequency value for that
					* widget. This will keep going until it returns a widget that is in the workbench.
					*/
					if(index == -1){
						//TODO: improve on this....
						bins[least]--;
					}
				} while(index == -1);
			}
		}
		getWidget(bin);
	}
	/*for (int i = 0; i < 100; i++) {
		//printf("%i\n", bins[i]);
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
			//printf("%d\n", i);
		}
	}
	return index;
}
