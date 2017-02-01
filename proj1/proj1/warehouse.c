//includes slots.h (an interface)
#include "slots.h"
#include <stdio.h>

int main(int argc, char ** argv) {
	int bin;
	initSlots();
	while(1==scanf("%d",&bin)) {
		if (-1==findSlot(bin)) {
			// getBin parameter should have a number between 0-3
			//did this update to github??
			getBin(bin,0);
		}
		getWidget(bin);
	}
	printEarnings();
	return 0;
}
