#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "function.h"

void printList(struct ListNode *node) {
	while (node) {
		printf("[%d] -> ", node->val);
		node = node->next;
		fflush(stdout);
		usleep(200000);
	}
	printf("NULL\n");
}
void freeAllNode(struct ListNode* n) {
	if (n) {
		freeAllNode(n->next);
		free(n);
	}
}

int main(int argc, char **argv){
	int nval;
	char tcString[32], *tcNextString;
	struct ListNode *tcList, *tcListTail, *res;
	struct ListNode *p;
	FILE *fptr = fopen("test_case", "r");
	
	while (fscanf(fptr, "%s%*c", tcString) != EOF) {
		printf("\nTesting List: %s\n", tcString);

		tcList = NULL;
		while ((tcNextString = strtok((!tcList) ? tcString : NULL, ",")) != NULL)  {
			nval = atoi(tcNextString);
			if (nval == 0)
				break;

			p = (struct ListNode *)malloc(sizeof(struct ListNode));
			p->val = nval;
			p->next = NULL;
			
			if (!tcList) {
				tcList = p;
				tcListTail = tcList;
			}
			else {
				tcListTail->next = p;
				tcListTail = tcListTail->next;
			}

		}
		printf("tcList: ");
		printList(tcList);

		res = deleteDuplicates(tcList);
		
		printf("   res: ");
		printList(res);
		
		freeAllNode(tcList);
	}

	fclose(fptr);

	return 0;
}
