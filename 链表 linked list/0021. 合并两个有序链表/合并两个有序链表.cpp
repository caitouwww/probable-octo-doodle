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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        ListNode* head=(l1->val<=l2->val)?l1:l2;
        ListNode* res=head;
        if(l1->val<=l2->val)
        {
            l1=l1->next;
        }
        else
        {
            l2=l2->next;
        }
        
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                head->next=l1;
                l1=l1->next;
            }
            else
            {
                head->next=l2;
                l2=l2->next;
            }
            head=head->next;
        }
        if(l1==NULL)
        {
            while(l2!=NULL)
            {
                head->next=l2;
                l2=l2->next;
                head=head->next;
            }
        }
        else
        {
            while(l1!=NULL)
            {
                head->next=l1;
                l1=l1->next;
                head=head->next;
            }
        }
        
        return res;*/
        ListNode* head=new ListNode(NULL);
        ListNode* c=head;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                c->next=l1;
                l1=l1->next;
            }
            else
            {
                c->next=l2;
                l2=l2->next;
            }
            c=c->next;
        }
        if(l1!=NULL)
            c->next=l1;
        else
        {
            c->next=l2;
        }
        return head->next;
    }
};