#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "function.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
	// Use Floyd's Algorithm
	struct ListNode *turtle = head, *rabbit = head;
	
	while (turtle && rabbit && rabbit->next) {
		turtle = turtle->next;
		rabbit = rabbit->next->next;
		if (turtle == rabbit)
			return true;
	}

	return false;
}
