#include <stdlib.h>
#include <stdio.h>
#include "function.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode *res = head, *curNode = head, *nxtNode;

	while (curNode) {
		while ((nxtNode = curNode->next) != NULL && 
			curNode->val == nxtNode->val)
		{
			curNode->next = nxtNode->next;
			free(nxtNode);
		}
		curNode = nxtNode;
	}
	return res;
}
