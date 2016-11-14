#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include "function.h"

int myAtoi(char* str) {
	int ret = 0, sign = 1;
	char *p = str;

	while (*p == ' ') {p++;}
	
	if (*p == '-' || *p == '+') {
		sign = (*p++ == '-') ? -1 : 1;
	}
	
	while (*p != '\0' && isdigit(*p)) {
		if (ret > INT_MAX/10 || (ret==INT_MAX/10 && *p > 0x37))
			return (sign > 0) ? INT_MAX : INT_MIN;

		ret = ret*10 + *p++ - 0x30;
	}
	
	
	return ret * sign;
}
