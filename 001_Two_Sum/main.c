#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "function.h"

int main(int argc, char **argv){
	int i, target, arrsize;
	int *input, *output;
	char tcString[64] = { 0 }, *tcNext;
	FILE *fptr = fopen("test_case", "r");
	
	while (fscanf(fptr, "%s%*c", tcString) != EOF) {
		printf("Testing Input: %s\n", tcString);

		tcNext = strtok(tcString, ",");
		target = atoi(tcNext);

		tcNext = strtok(NULL, ",");
		arrsize = atoi(tcNext);
		
		input = (int *)malloc(sizeof(int) * arrsize);
		
		i = 0;	
		while ((tcNext = strtok(NULL, ",")) != NULL) {
			input[i] = atoi(tcNext);
			i++;
		}
		
		printf("target: %d\n", target);
		printf("array: ");
		for (i=0; i<arrsize; i++)
			printf("%d ", input[i]);
		printf("\n");

		output = twoSum(input, arrsize, target);

		printf("%d = %d + %d\n\n", target, output[0], output[1]);
		free(input);
	}

	fclose(fptr);

	return 0;
}
