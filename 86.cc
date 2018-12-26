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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* itr = head;
        ListNode* new_head = NULL;
        ListNode* tail = NULL;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while (itr != NULL) {
            next = itr->next;
            if (itr->val < x) {
                if (new_head == NULL) {
                    new_head = itr;
                    tail = itr;
                } else {
                    tail->next = itr;
                    tail = itr;
                    tail->next = NULL;
                }
                
                if (prev == NULL) {
                    head = next;
                } else {
                    prev->next = next;
                }
            } else {
                prev = itr;
            }
            
            itr = next;
        }
        
        if (!!tail) {
            tail->next = head;
        }
        
        return new_head != NULL? new_head : head;
    }
};

