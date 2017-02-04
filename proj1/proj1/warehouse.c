//includes slots.h (an interface)
#include "slots.h"
#include <stdio.h>

int main(int argc, char ** argv) {
	int bin;
	int index = 0;
	initSlots();
	//as long as there are more bin numbers on the order for the kit....continunes onto the while loop
	while(1 == scanf("%d",&bin)) {
		if (-1==findSlot(bin)) {
			// getBin index should have a number between 0-3
			if(bin < 0 || bin > 99){
				//if customer orders something that we don't have.
				return -1;
			} else {
				getBin(bin,index);
				if(index < 3){
					index++;
				} else {
					index = 0;
				}
			}
		}
		getWidget(bin);
	}
	printEarnings();
	return 0;
}
