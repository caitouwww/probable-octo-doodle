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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(NULL);
        dummy->next=head;
        ListNode* p=head;
        int len=1;
        while(p!=NULL)
        {
            p=p->next;
            len++;
        }
        int cnt=1;
        p=head;
        ListNode* prev=dummy;
        while(cnt!=len-n)
        {
            cnt++;
            prev=p;
            p=p->next;
        }
        prev->next=p->next;
        p->next=NULL;
        return dummy->next;
    }
};