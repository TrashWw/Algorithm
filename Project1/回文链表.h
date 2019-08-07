#pragma once
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
public:
	bool isPalindrome(ListNode* head) {

		if (head == NULL || head->next == NULL)
			return true;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast->next != NULL&&fast->next->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* pPre = slow;
		ListNode* pNow = slow->next;
		ListNode* pNext = NULL;
		while (pNow != NULL) {
			pNext = pNow->next;
			pNow->next = pPre;
			pPre = pNow;
			pNow = pNext;
		}
		while (head != slow->next) {
			if (head->val != pPre->val) {
				return false;
			}
			head = head->next;
			pPre = pPre->next;
		}
		return true;
	}

	Solution() {
		head->next = new ListNode(2);
	}

	ListNode *head = new ListNode(1);

};