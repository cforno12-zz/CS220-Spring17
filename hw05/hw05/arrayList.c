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

void arrayListFree(arrayList list) {
	free(list->data);
	free(list);
}

/* Put definitions of the other arrayList methods in arrayList.h here */

bool arrayListAdd(arrayList list, int item){
	assert(list);
	if(list->numAlloc == list->numUsed){
		if(arrayListEnlarge(list)){
			arrayListAdd(list,item);
		} else {
			return false;
		}
	}
	list->data[list->numUsed++] = item;

	return true;
}
void arrayListClear(arrayList list){
	assert(list);
	list->numUsed=0;
}
bool arrayListContains(arrayList list, int item){
	assert(list);
	int i;
	for (i = 0; i < list->numUsed; i++) {
		if(list->data[i] == item){
			return true;
		}
	}
	return false;
}
int arrayListGet(arrayList list,int index){
	assert(list);
	return list->data[index];
}
int arrayListIndexOf(arrayList list, int item){
	assert(list);
	//should return a -1 if it cannot find its argument in the arrayList,
	//just like the Java "indexOf" method.
	int retVal = -1;
	int i;
	for (i = 0; i < list->numUsed; i++) {
		if(list->data[i] == item){
			retVal = i;
			break;
		}
	}
	return retVal;
}
bool arrayListIsEmpty(arrayList list){
	assert(list);
	return (list->numUsed == 0);
}
int arrayListSet(arrayList list, int index, int item){
	assert(list);
	int retVal = 0;
	if(index > list->numUsed){
		retVal = list->data[index];
		list->data[index] = item;
	}
	return retVal;

}
int arrayListSize(arrayList list){
	return list->numUsed;
}
char * arrayListToString(arrayList list,char *buffer){
	assert(list);
	buffer[0] = 0;
	strcat(buffer, "[");
	int i;
	for (i = 0; i < list->numUsed; i++) {
		char temp[10];
		sprintf(temp, "%d", list->data[i]);
		strcat(buffer, temp);
		if (i!=list->numUsed-1) {
			strcat(buffer, ", ");
		}
	}
	strcat(buffer, "]");
	return buffer;
	//should be written into the space provided by your caller in the
	//"buffer" argument, and you should return the buffer when you are finished
}
