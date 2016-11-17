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
	int val;
	struct ListNode *curNode = head, *nxtNode = NULL;

	if (!head || !head->next) return head;

	val = curNode->val;
	nxtNode = curNode->next;
	if (val != nxtNode->val) {
		curNode->next = deleteDuplicates(nxtNode);
		return curNode;
	}
	else {
		while (nxtNode && (val == nxtNode->val)) {
			struct ListNode *tmp = nxtNode->next;
			free(nxtNode);
			nxtNode = tmp;
		}
		free(curNode);
		return deleteDuplicates(nxtNode);
	}
}
