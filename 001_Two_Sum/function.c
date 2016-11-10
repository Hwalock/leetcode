#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "function.h"

int compare(const void *a, const void *b) {
	int c = *(int *)a;
	int d = *(int *)b;
	if(c < d)
		return -1;
	else if (c == d)
		return 0;
	else 
		return 1;
}

int bbsearch(int *nums, int numsSize, int target) {
	int i = 0, j = numsSize-1, k;
	
	while (i<=j) {
		k = (i+j)/2;
		if (target == nums[k])
			return k;
		else if (target > nums[k])
			i = k+1;
		else
			j = k-1;
	}
	return -1;
	
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	int i, k;
	int find, targetidx, findidx;
	int *out = malloc(sizeof(int) * 2);
	int *newnums = malloc(sizeof(int) * numsSize);
	
	memcpy(newnums, nums, sizeof(int) * numsSize);

	qsort((void *)newnums, (size_t)numsSize, sizeof(int), compare);
	
	for (i = numsSize - 1; i >= 0; --i) {
		targetidx = i;
		find = target - newnums[i];
		
		if (find <= 0)
			continue;

		findidx = bbsearch(newnums, i, find);
		if (findidx == -1) {
			continue;
		}
		else {
			for (k=0; k<numsSize; k++) {
				if (nums[k] == newnums[findidx])
					out[0] = k;
				if (nums[k] == newnums[targetidx])
					out[1] = k;
			}
			if (out[0] > out[1]) {
				out[0] ^= out[1];
				out[1] ^= out[0];
				out[0] ^= out[1];
			}
			break;
		}
	}
	return  out;
}
