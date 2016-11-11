#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "function.h"

int main(int argc, char **argv){
	int numRows;
	char input[128], *output;

	char tcString[128] = { 0 }, *tcNext;
	FILE *fptr = fopen("test_case", "r");
	
	while (fscanf(fptr, "%s%*c", tcString) != EOF) {
		printf("Testing Input: %s\n", tcString);

		tcNext = strtok(tcString, ",");
		numRows = atoi(tcNext);
		
		tcNext = strtok(NULL, ",");
		snprintf(input, 128, "%s", tcNext);
		
		printf("[%d] input: %s\n", numRows, input);

		output = convert(input, numRows);

		printf("output: %s\n\n", output);
		free(output);
	}

	fclose(fptr);

	return 0;
}
