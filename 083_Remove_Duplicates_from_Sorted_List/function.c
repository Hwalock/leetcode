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
	struct ListNode *res = head, *curNode = head;

	while (curNode && curNode->next) {
		if (curNode->val == curNode->next->val)
		{
			struct ListNode *tmp = curNode->next;
			curNode->next = curNode->next->next;
			free(tmp);
		}
		else {
			curNode = curNode->next;
		}
	}
	return res;
}
