#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "function.h"

int reverse(int x) {
	int ret = 0;
	if (x==0)
		return 0;
	
	while (x != 0) {
		int tmpret = ret*10 + x%10;
		int tmpdig = x%10;
		if ((tmpret - tmpdig) / 10 != ret )
			return 0;

		ret = tmpret;
		x /= 10;
	}

	return ret;
}
