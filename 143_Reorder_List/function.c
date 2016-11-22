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
extern void printList(struct ListNode *node);

void reorderList(struct ListNode* head) {
	struct ListNode *p1 = head, *p2 = head, *preNode = NULL;

	if (!head || !head->next) return;

	// Find middle of list, then separate it
	while (p2->next && p2->next->next) {
		p1 = p1->next;
		p2 = p2->next->next;
	}
	p2 = p1->next;
	p1->next = NULL;
	p1 = head;

	// Reverse second list
	while (p2 != NULL) {
		struct ListNode *nextNode = p2->next;
		p2->next = preNode;
		preNode = p2;
		p2 = nextNode;
	}

	// Merge 2 lists
	p2 = preNode;
	while(p1 && p2) {
		struct ListNode *next1 = p1->next;
		struct ListNode *next2 = p2->next;

		p1->next = p2;
		p2->next = next1;

		p1 = next1;
		p2 = next2;
	}

	return head;
}
