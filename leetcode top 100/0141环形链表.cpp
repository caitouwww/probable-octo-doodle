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
    bool hasCycle(ListNode *head) {
        if(head==nullptr)return false;
        ListNode* slow = head;
        ListNode* fast = nullptr;
        if(slow->next)fast = slow->next;
        else return false;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
            if(fast->next)fast=fast->next;
            else return false;
            if(slow==fast)return true;
        }
        return false;
    }
};
