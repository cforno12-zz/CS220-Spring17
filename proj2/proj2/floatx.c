#include "floatx.h"

/*--------------------------------------------------------------------------------
	Return floatx representation (as defined by *def) which
	best approximates value
-------------------------------------------------------------------------------- */

floatx doubleToFloatx(const floatxDef *def, double value) {

	floatx bits = *((floatx*)&value);
	int fracBits = def->totBits - def->expBits - 1;
	floatx retVal = 0;

	bits -= 1023;
    bits = (bits << (def->expBits - 1)) - 1;

    
 
	// I started with making a helper function to get a range of bits from a number.
	// You need to take those and convert them into smaller bits.
	// The fraction is the rest of the bits and you can just throw out the ones at the end you don't need.
	// Use some bit shifting for that.
	// You have to look at the individual bits of the value, the first bit is the sign bit, the next 11 are the exponent and the next 52 are the fraction.
	// You can just truncate the fraction to however many bits the definition calls for but you have to convert the exponent by subtracting 1023 and then adding 2^(expBits-1)-1 to it.
	return retVal;
}

/*
 * Return C double with value which best approximates that of floatx fx
 * (as defined by *def).
 */
double floatxToDouble(const floatxDef *def, floatx fx) {

	double bits = *((double*)&fx);
	int fractBits = def->totBits - def->expBits - 1;
	double retVal = 0.0;



	return retVal;
}

int pow_of_two(int exponent){
	int retVal = 1;
	int i;
	for (i = 0; i < exponent; i++) {
		retVal *= 2;
	}
}
