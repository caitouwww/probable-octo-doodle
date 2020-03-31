/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //ListNode* front;
class Solution {
public:
    /*bool recursiveCheck(ListNode * cur)
        {
            if(cur!=NULL)
            {
                if(!recursiveCheck(cur->next))
                {
                    return false;
                }
                if(cur->val!=front->val)
                    return false;
                front=front->next;
            }
            return true;
        }*/
    bool isPalindrome(ListNode* head) {
        /*vector<int> res;
        ListNode* p = head;
        while(p!=NULL)
        {
            res.push_back(p->val);
            p=p->next;
        }
        int i=0;
        for(vector<int>::iterator iter=res.end();iter!=res.begin();)
        {
            if(*(--iter)!=res[i++])
                return false;
        }
        return true;*/
        /*front=head;
        return recursiveCheck(head);*/
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pre=head;
        ListNode* prepre=new ListNode(NULL);
        while(fast!=NULL&&fast->next!=NULL)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
            pre->next=prepre;
            prepre=pre;
        }
        if(fast!=NULL)
        {
            slow=slow->next;
        }
        while(pre!=NULL&&slow!=NULL)
        {
            if(pre->val!=slow->val)
                return false;
            pre=pre->next;
            slow=slow->next;
        }
        return true;
    }
/*private:
ListNode* front;*/
};