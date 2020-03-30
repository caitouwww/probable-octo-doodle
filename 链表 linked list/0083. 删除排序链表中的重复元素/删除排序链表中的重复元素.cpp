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
        /*ListNode* res=head;
        ListNode* end=head;
        ListNode* start=head;
        while(end!=NULL)
        {
            while(end!=NULL&&end->val==start->val) end=end->next;
            if(end!=NULL)
            {
                start->next=end;
                start=start->next;
            }
            else
            {
                start->next=NULL;
            }
            
        }
        return res;*/
        ListNode* ans=head;
        while(head!=NULL)
        {
            if(head->next!=NULL&&head->next->val==head->val)
                head->next=head->next->next;
            else
                head=head->next;
        }
        return ans;
    }
};