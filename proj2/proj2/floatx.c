#include "floatx.h"

/*--------------------------------------------------------------------------------
  Return floatx representation (as defined by *def) which
  best approximates value
  -------------------------------------------------------------------------------- */
floatx doubleToFloatx(const floatxDef *def, double value) {
    floatx retVal = (floatx) malloc(sizeof(floatx));
    if(def->totBits == sizeof(value)){
        
    }
}

/** Return C double with value which best approximates that of floatx fx
 *  (as defined by *def).
 */
double floatxToDouble(const floatxDef *def, floatx fx) {
	double retVal = 0.0;

    

	return retVal;
}
