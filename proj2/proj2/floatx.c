#include "floatx.h"

/*--------------------------------------------------------------------------------
	Return floatx representation (as defined by *def) which
	best approximates value
-------------------------------------------------------------------------------- */
void print_bits(floatx ip);
floatx doubleToFloatx(const floatxDef *def, double value) {

	floatx allBits = *((floatx*)&value);
	int fracBitNum = def->totBits - def->expBits - 1;
	int expBitNum = def->expBits;
	floatx retVal = 0;

	long bias = 1023; //bias for double data type
	// masking to get only the exponent bits
	floatx getExp = (allBits >> 52) & 0b11111111111;
	floatx getFrac = (allBits >> (51 - fracBitNum)) & 0b11111111111;
	getExp -= bias;
	getExp += (1 << (def->expBits - 1)) - 1;
	//print_bits(getExp);
	// You can just truncate the fraction to however many bits the definition calls for.
	// But you have to convert the exponent by subtracting 1023 and then adding 2^(expBits-1)-1 to it.
	/*
	* Okay so for denormalized numbers: if the unbiased exponent is less than or equal to 0
	* then you know its going to be denormal.
	* Denormalized numbers shift the fraction depending on how far off the exponent is from
	* whats representable.
	* So for example if the exp is 130 which would make the biased exponent -3 or
	* something then you have to shift the fraction 3 to the right and thats your number.
	* Before that I do a check to make sure the number isnt too small by calculating the smallest
	* representable value with the given definition
	* so if the given double value is smaller than:
	* double smallest = 1/pow(2, fBits-1)*pow(2, (-pow(2, (def->expBits-1))+1));
	* then I just return 0
	*/
	return getExp;
}

/*
 * Return C double with value which best approximates that of floatx fx
 * (as defined by *def).
 */
double floatxToDouble(const floatxDef *def, floatx fx) {

	/*double allBits = *((double*)&fx);
	int fractBitNum = def->totBits - def->expBits - 1;
	double retVal = 0.0;

	int bias = (1 << (def->expBits - 1)) - 1;


	return retVal;*/
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
