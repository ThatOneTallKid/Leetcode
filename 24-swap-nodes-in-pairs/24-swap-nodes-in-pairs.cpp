/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        // ListNode* curr = head;
        // int temp;
        // while(curr  != NULL && curr -> next != NULL)
        // {
        //     temp = curr->val;
        //     curr->val = curr -> next->val;
        //     curr -> next->val = temp;
        //     curr = curr -> next;
        //     if(curr != NULL)
        //         curr = curr ->next;
        // }
        // return head;
        ListNode **pp = &head, *a, *b;
        while ((a = *pp) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
};