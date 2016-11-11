#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "function.h"

char* convert(char* s, int numRows) {
	int i, j, way;
	size_t slen = strlen(s);
	char **out = NULL, *output;
	
	out = malloc(numRows * sizeof(char *));
	output = malloc(slen+1);
	memset(output, 0x00, slen+1);
	if (numRows == 1) {strcpy(output, s); return output;}
	for (i=0; i<numRows; ++i) {
		out[i] = malloc(2*slen/numRows + 2);
		memset(out[i], 0x00, 2*slen/numRows+2);
	}
	for (i=0, j=0, way=1; i<slen; i++, j+=way) {
		char tmp[2] = {0};
		tmp[0] = s[i];
		strcat(out[j], tmp);
		if (j==(numRows-1))
			way = -1;
		else if	(j==0)
			way = 1;
	}
	for (i=0, s[0]='\0'; i<numRows; ++i) {
		strcat(output, out[i]);
		free(out[i]);
	}
	free(out);
	return output;
}
#if 0
char* convert(char* s, int numRows) {
    int     i, j, k;
    char    *str;
    size_t  slen;

    if((str = (char *)malloc(1+strlen(s)*sizeof(char))) == NULL)
        return NULL;

    slen = strlen(s);

    for(i = 0, k = 0; i < numRows; i++){
        for(j = i; j < slen; j += (numRows==1 ? 1 : numRows+1)){
            str[k++] = *(s+j);
            if( i != (numRows-1) &&
                i == 1 &&
                (j+numRows-1) < slen)
            {
                str[k++] = *(s+j+numRows-1);
            }
        }
    }

    str[k] = '\0';

    return str;
}
#endif
