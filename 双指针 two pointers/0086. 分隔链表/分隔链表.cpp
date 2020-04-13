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
        ListNode* dummy=new ListNode(NULL);
        dummy->next=head;
        ListNode* first=dummy;
        ListNode* second_prev=dummy;
        ListNode* second=head;
        while(second!=NULL)
        {
            if(second->val<x)
            {
                second_prev->next=second->next;
                second->next=first->next;
                first->next=second;
                first=first->next;
            }
            second_prev=second;
            second=second->next;
        }
        return dummy->next;
    }
};