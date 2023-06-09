#ifndef SRC_PN_H_
#define SRC_PN_H_
#include <math.h>

#include "conditions.h"
#include "stack.h"

void convert_to_pn(char* expr_in, char* expr_pn);
double symb_to_number(char value, int* len_value);
st_calc* operation(char c, st_calc* pn);
st_calc* function(char c, st_calc* pn);

#endif  // SRC_PN_H_
