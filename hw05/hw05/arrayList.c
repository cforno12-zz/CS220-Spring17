#include "arrayList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#define INITSIZE 16

bool arrayListEnlarge(arrayList list);

arrayList arrayListCreate() {
	arrayList list = (arrayList)malloc(sizeof(struct arrayListStruct));
	if (list==NULL) return list;
	//a pointer to the actual list of data itmes
	list->data=(int *)malloc(sizeof(int)*INITSIZE);
	//variable to keep track of how many data items are being used in the arrayList
	list->numUsed=0;
	//keeps track of the number of spaces for items available
	list->numAlloc=INITSIZE;
	return list;
}

bool arrayListEnlarge(arrayList list) {
	list->data=(int *)realloc(list->data,sizeof(int) * (2*list->numAlloc));
	if (list->data==NULL) return false;
	list->numAlloc *=2;
	return true;
}

/* Put definitions of the other arrayList methods in arrayList.h here */

bool arrayListAdd(arrayList list, int item){
	assert(list);
	if(list->numAlloc == 0){
		return false;
	}
	while (*list->data != NULL) {
		list->data++;
	}
	*list->data = item;
	list->numAlloc--;
	list->numUsed++;
}
void arrayListClear(arrayList list){
	assert(list);
	int i;
	while (list->numUsed != 0) {
		*list->data = NULL;
		list->data++;
		list->numUsed--;
	}
}
bool arrayListContains(arrayList list, int item){
	assert(list);
	while (*list->data != NULL) {
		if (*list->data == item) {
			return true;
		} else {
			list->data++;
		}
	}
	return false;

}
int arrayListGet(arrayList list,int index){
	assert(list);
	
}
int arrayListIndexOf(arrayList list, int item){
	assert(list);
	//should return a -1 if it cannot find its argument in the arrayList,
	//just like the Java "indexOf" method.
}
bool arrayListIsEmpty(arrayList list){
	assert(list);
}
int arrayListSet(arrayList list, int index, int item){
	assert(list);
}
int arrayListSize(arrayList list){

}
char * arrayListToString(arrayList list,char *buffer){
	assert(list);
	//should be written into the space provided by your caller in the
	//"buffer" argument, and you should return the buffer when you are finished
}

void arrayListFree(arrayList list) {
	free(list->data);
	free(list);
}
