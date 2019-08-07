#pragma once
#include <iostream>

 
 struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* merge(ListNode* A, ListNode* B) {
		if (A == NULL&&B == NULL)
			return NULL;
		else if (B == NULL)
			return A;
		else if (A == NULL)
			return B;

		ListNode* ans = NULL;
		if (A->val>B->val)
			ans = B;
		else
			ans = A;

		ListNode* tmp = NULL;
		ListNode * tmp_b = NULL;
		ListNode* tail = NULL;
		while (A != NULL&&B != NULL) {
			if (A->val>B->val) {
				tmp = B;
				B = B->next;
				tmp->next = A;
				if (tmp_b != NULL)
					tmp_b->next = tmp;
				else
					tmp_b = tmp;
				tmp = NULL;
			}
			else {
				if (A->next == NULL)
					tail = A;
				tmp_b = A;
				A = A->next;
			}
		}
		if (B != NULL)
			tail->next = B;
		return ans;

	}

	ListNode* sortList(ListNode* head) {
		if (head == NULL||head->next==NULL)
			return head;
		
		ListNode* start = head;
		ListNode* end = NULL;
		int size = 0;
		while (start != NULL) {
			start = start->next;
			++size;
		}
		start = head;
		size /= 2;
		while(size>0){
			if (size == 1) {
				 end = start;
			}
			start = start->next;
			if(size == 1)
				end->next = NULL;
			--size;
		}
		ListNode* l1 = sortList(head);
		ListNode* l2 = sortList(start);
		ListNode* ans = merge(l1, l2);
		return ans;
	}
};