#include <stdlib.h>
#include <stdio.h>

int climbStairs(int n) {
	int i;
	int *step, result;

	if (n == 0)	
		return 0;
	
	step = malloc(sizeof(int) * n);

	step[0] = 1;
	step[1] = 2;
	
	for (i = 2; i < n; i++)
		step[i] = step[i-2] + step[i-1];
	
	result = step[n-1];
	free(step);

	return result;
}
