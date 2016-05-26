#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "function.h"

#ifdef DEBUG
void printList(struct ListNode *node) {
	while (node) {
		printf("[%d] -> ", node->val);
		node = node->next;
		fflush(stdout);
		sleep(1);
	}
	printf("NULL\n");
}
#endif

int main(int argc, char **argv){
	int tcThisIdx, tcNextIdx;
	char tcString[32], *tcNextString;
	bool cycle;
	struct ListNode *tcList;
	FILE *fptr = fopen("test_case", "r");
	
	while (fscanf(fptr, "%s%*c", tcString) != EOF) {
		printf("Testing List: %s\n", tcString);

		tcList = (struct ListNode *)malloc(sizeof(struct ListNode) * strlen(tcString) / 2 + 1);

		tcThisIdx = 0;
		tcNextIdx = -1;
		while (tcNextIdx != 0 &&
			(tcNextString = strtok((tcNextIdx == -1) ? tcString : NULL, ",")) != NULL) 
		{
			tcNextIdx = atoi(tcNextString);

			tcList[tcThisIdx].val = tcThisIdx;
			tcList[tcThisIdx].next = (tcNextIdx != 0) ? &tcList[tcNextIdx] : NULL;

			tcThisIdx = tcNextIdx;
		}

		cycle = hasCycle(tcList);

		printf("\tIt has %scycle\n\n", (cycle) ? "" : "not ");
		free(tcList);
	}

	fclose(fptr);

	return 0;
}
