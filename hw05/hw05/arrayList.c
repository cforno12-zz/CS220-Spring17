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
	list->data=(int *)malloc(sizeof(int)*INITSIZE);
	list->numUsed=0;
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
	//increment numUsed by 1
	//
}
void arrayListClear(arrayList list){
	assert(list);
	list->numUsed = 0;
}
bool arrayListContains(arrayList list, int item){
	assert(list);
	int retVal = false;
	if(*list->data == item){
		retVal = true;
	} else if(list->data == NULL){
		retVal = false;
	} else {
		arrayListContains(list->data, item);
	}
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
