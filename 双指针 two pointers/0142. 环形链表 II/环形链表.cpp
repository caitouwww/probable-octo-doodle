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
    ListNode *detectCycle(ListNode *head) {
        //步骤一：使用快慢指针判断是否有环
        if(head==NULL)  return head;
        ListNode* slow=head,*fast=head;
        bool hasCycle=false;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                hasCycle=true;
                break;
            }
        }
        if(hasCycle)
        {
            ListNode* q=head;
            while(q!=slow)
            {
                slow=slow->next;
                q=q->next;
            }
            return q;
        }
        else    return NULL;
    }
};
