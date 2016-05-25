#include <stdlib.h>
#include <stdio.h>
#include "function.h"

int main(int argc, char **argv){
	int step;
	
	if (argc == 1)
		return -1;
	
	
	step = climbStairs(atoi(argv[1]));
	printf("climbing stairs: %d\n", step);
	
	return 0;
}
