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
        if(head==NULL)
            return false;
        ListNode* first = head;
        ListNode* second=first->next;
        int pos=-1;
        while((first->next!=NULL)&&(second->next!=NULL)&&(second->next->next!=NULL))
        {
            pos++;
            if(first==second)
            {
                return true;
            }
            else
            {
                first=first->next;
                second=second->next->next;
            }
        }
        return false;
    }
};