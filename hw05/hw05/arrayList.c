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

void arrayListFree(arrayList list) {
	free(list->data);
	free(list);
}