#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "stack.h"

void printStackInfo() {
	int j,nptrs;
#define BUFSIZE 100
	void *buffer[BUFSIZE];
	char **strings;
	/* ------------------------------------------------------------------------------------------------------
		There are system (gnu) library functions called backtrace and
		backtrace_symbols which trace the call stack and find information
		about the function, and if the -rdynamic parameter is included at
		compile time allow you to get the function name and offset.
		See http://man7.org/linux/man-pages/man3/backtrace.3.html
	-------------------------------------------------------------------------------------------------------*/

	nptrs=backtrace(buffer,BUFSIZE); // One address is stored in buffers for each stack frame
	// printf("backtrace() returned %d addresses\n",nptrs);

	strings = backtrace_symbols(buffer,nptrs); // Get the text description of each address
	if (strings==NULL) {
		perror("backtrace_symbols()");
		exit(EXIT_FAILURE);
	}

	register void * rbp asm ("rbp"); // Access the value of the %rbp register with a C variable!
	register void * rsp asm ("rsp"); // Acess %rsp with a C variable;
	void * frameTop=rbp;
	void * frameBot=rsp;

	for(j=0;j<nptrs; j++) {
		printf("%2d : %s Frame: %p to %p \n",j,strings[j],frameTop,frameBot);
		if (frameTop) { // Since the OS zeroes %rbp before calling main, if we are above main, frameTop will be 0
			frameBot=frameTop-8; // Point frameBot at the caller's stack frame bottom
			frameTop=(void *)(*(void **)frameTop); // Point frameTop at the caller's stack frame top
		} else {frameBot=NULL; } // if we are above main, set frameBot to zero also
	}
	free(strings); // The backtrace symbols function malloced what strings points to
}
void printFrameField(int frame,int offset,enum dtype_enum dtype,char * desc) {

	/* First, get the top and bottom address of the stack frame of interest */
	/* The "frame" variable indicates how many stack frames above the current stack frame */
	/*    e.g. frame=0 is the current stack frame, frame=1 is the caller's stack frame, ... */

	/* Next, find the address of the field */
	/* The offset is the number of bytes below the top of the frame */
	/* Since we haven't looked at the type yet, leave this as a void pointer */

	/* First, print the description passed in as an argument */
    	int j,nptrs;
#define BUFSIZE 100
	void *buffer[BUFSIZE];
	char **strings;
	/* ------------------------------------------------------------------------------------------------------
		There are system (gnu) library functions called backtrace and
		backtrace_symbols which trace the call stack and find information
		about the function, and if the -rdynamic parameter is included at
		compile time allow you to get the function name and offset.
		See http://man7.org/linux/man-pages/man3/backtrace.3.html
	-------------------------------------------------------------------------------------------------------*/

	nptrs=backtrace(buffer,BUFSIZE); // One address is stored in buffers for each stack frame
	// printf("backtrace() returned %d addresses\n",nptrs);

	strings = backtrace_symbols(buffer,nptrs); // Get the text description of each address
	if (strings==NULL) {
		perror("backtrace_symbols()");
		exit(EXIT_FAILURE);
	}

	register void * rbp asm ("rbp"); // Access the value of the %rbp register with a C variable!
	register void * rsp asm ("rsp"); // Acess %rsp with a C variable;
	void * frameTop=rbp;
	void * frameBot=rsp;

	for(j=0;j<nptrs; j++) {
        if(frame==j) break;
		if (frameTop) { // Since the OS zeroes %rbp before calling main, if we are above main, frameTop will be 0
			frameBot=frameTop-8; // Point frameBot at the caller's stack frame bottom
			frameTop=(void *)(*(void **)frameTop); // Point frameTop at the caller's stack frame top
		} else {frameBot=NULL; } // if we are above main, set frameBot to zero also
	}
	free(strings); // The backtrace symbols function malloced what strings points to

    void * address = frameTop-offset;

	printf("%s",desc);

	/* Next print the actual value... the printf format will be different
	   and the access may be slightly different, depending on what
	   type of data the field is... the value of dtype */
	switch(dtype) {
    case(int_type):
        printf("%d", *(int *)address);
        break;
    case(long_type):
        printf("%f", *(long *) address);
        break;
    case(char_type):
        printf("%c", *(char *) address);
        break;
    case(addr_type):
        printf("%p", *(void**) address);
        break;
	default: printf("???"); // Don't know how to print this value yet
	}
}
