#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
	int		i = 0, j = 0, flag = 0;
	char	c1, *s;
	size_t	tmp_len, min_len = 0, pfx_len = 0;
	
	for (i = 0; i < strsSize; i++) {
		if (strs[i] == NULL)
			return "";
		else if (i == 0)
			min_len = strlen(strs[i]);
		
		tmp_len = strlen(strs[i]);
		min_len = (tmp_len < min_len) ? tmp_len : min_len;
	}

#ifdef DEBUG
	printf("min_len: %zu\n", min_len);
#endif

	for (i = 0, j = 0; j < min_len && flag == 0; i = 0, j++) {
		for (i = 0, c1 = strs[i][j]; i < strsSize && flag == 0; i++) {
#ifdef DEBUG
			printf("  checking strs[%d][%d]:%c\n", i, j, strs[i][j]);
#endif

			if (c1 != strs[i][j])
				flag = 1;
		}
		if (flag == 0)
			pfx_len++;
	}

#ifdef DEBUG
	printf("max common prefix length: %zu\n", pfx_len);
#endif

	s = (char *)malloc(sizeof(char) * pfx_len + 1);
	memset(s, 0x00, pfx_len+1);	
	strncpy(s, strs[0], pfx_len);
	
	return s;
}

