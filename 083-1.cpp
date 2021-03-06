/*
083. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = head;
        ListNode* next = cur->next;

        while(next) {
            if(next->val != cur->val) {
                next = next->next;
                cur = cur->next;
            } else {
                cur->next = next->next;
                next = next->next;
            }
        }
        return dummy.next;
    }
};
