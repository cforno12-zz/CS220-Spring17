#include "floatx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*--------------------------------------------------------------------------------
	Return floatx representation (as defined by *def) which
	best approximates value
-------------------------------------------------------------------------------- */
void print_bits(floatx ip);
floatx doubleToFloatx(const floatxDef *def, double value) {
	if(value == 0){
		return 0;
	}
	floatx allBits = *((floatx*)&value);
	int floatFracNum = def->totBits - def->expBits - 1;
	int doubleSize = sizeof(value)*8;
	int doubleFracNum = 52;
	int doubleExpNum = 11;
	floatx retVal = 0;
	int doubleBias = pow(2, doubleExpNum-1)-1; //bias for double data type
	/*----------------------------------------*/
	// moving sign, exp, and frac bits all the way to the right,
	// while zeroing out everything to the left

	//sign bit
	floatx sign = allBits >> (doubleSize - 1);

	//expBits
	floatx tempExp = allBits << 1;
	floatx getExp = tempExp >> (doubleFracNum + 1);
	getExp -= doubleBias;

	//fracBits
	floatx tempFrac = allBits << (doubleExpNum + 1);
	floatx getFrac = tempFrac >> (doubleSize - floatFracNum - 1);

	/*----------------------------------------*/
	//Rounding fraction bits
	int rounding = getFrac % 2;
	if(rounding == 1){
		getFrac >>= 1;
		getFrac += 0x1;
	} else {
		getFrac >>= 1;
	}
	/*----------------------------------------*/
	//checking for infinity
	if((signed long)getExp >= doubleBias){
		getExp = pow(2, def->expBits) - 1;
	} else if((signed long)getExp >= (pow(2, def->expBits-1) - 1)){
		getExp = pow(2, def->expBits) - 1;
		getFrac = 0;
	} else {
		getExp += pow(2,(def->expBits - 1)) - 1;
	}
	/*-------------------------------------------*/
	//DENORMAL NUMBERS
	double smallest = (1/pow(2, floatFracNum-1)) * pow(2, (- pow(2, (def->expBits-1))+1));
	//if given the smallest possible denormal number, return 0.
	if(value == smallest){
		return 0;
	}
	if ((signed long)getExp <= 0) {
		signed long shift = (signed long) getExp;
		shift *= -1;
		getExp = 0;
		floatx newFrac = allBits << 12;
		newFrac >>= 12;
		newFrac >>= (51 - floatFracNum + shift + 2);
		newFrac |= ((floatx) 1 << (floatFracNum - (1 + shift)));
		getFrac = newFrac;
	}
	/*-------------------------------------------*/

	/*-------------------------------------------*/
	//Putting everything together
	retVal += sign << (def->totBits - 1);
	retVal += getExp << floatFracNum;
	retVal += getFrac;

	return retVal;

}

/*
 * Return C double with value which best approximates that of floatx fx
 * (as defined by *def).
 */
double floatxToDouble(const floatxDef *def, floatx fx) {


    union{
        floatx flx;
        double db;
    } both;

	double retVal = 0;
    floatx tempReturn = 0;

    //floatx variables to keep track
	int floatSize = def->totBits;
	int floatFracNum = def->totBits - def->expBits - 1;
	int floatExpNum = def->expBits;
	int floatBias = pow(2, (floatExpNum - 1)) - 1;

    //double variables to keep track of
	int doubleSize = sizeof(retVal)*8;
	int doubleFracNum = 52;
	int doubleExpNum = 11;
	int doubleBias = pow(2, (doubleExpNum-1))-1;

    fx <<= (doubleSize - floatSize + 1);

    //getting sign bit from floatx
    floatx sign = fx >> (doubleSize - 1);

    //getting exp bits from floatx
    floatx tempExp = fx << 1;
    floatx getExp = tempExp >> (doubleSize - floatExpNum + 1);

    getExp -= floatBias;
    getExp += doubleBias;

    //getting fracBits from floatx
    floatx tempFrac = fx << (floatExpNum + 1);
    floatx getFrac = tempFrac >> (doubleSize - doubleFracNum + 1);

    //putting everything together
    tempReturn += getExp << (doubleFracNum + 1);
    tempReturn += getFrac;


    both.flx = tempReturn;
    retVal = both.db;
	return retVal;
}

void print_bits(floatx ip){
	char *bytes = malloc(8*sizeof(floatx)+1);
	floatx i;
	for(i=(floatx)1<<(8*sizeof(floatx)-1);i>0;i>>=1){
		(*bytes) = ((ip&i) == i) ? '1' : '0';
		bytes++;
	}
	*bytes=0;
	printf("%s\n", (bytes-8*sizeof(floatx)));
}
