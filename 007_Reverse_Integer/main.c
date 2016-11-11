#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "function.h"

int main(int argc, char **argv){
	int output;

	char tcString[128] = { 0 };
	FILE *fptr = fopen("test_case", "r");
	
	while (fscanf(fptr, "%s%*c", tcString) != EOF) {
		printf("Testing Input: %s\n", tcString);

		output = reverse(atoi(tcString));
		printf("output: %d\n\n", output);
	}

	fclose(fptr);

	return 0;
}
