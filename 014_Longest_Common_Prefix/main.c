#include <stdlib.h>
#include <stdio.h>
#include "function.h"

int main(int argc, char **argv){
	char *lcp;

	lcp = longestCommonPrefix(&(argv[1]), argc - 1);
	printf("Longest Common Prefix: %s\n", lcp);
	free(lcp);
	
	return 0;
}
