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
    ListNode* removeElements(ListNode* head, int val) {
        //添加虚拟头节点，迭代
        /*ListNode* res=new ListNode(NULL);
        res->next=head;
        ListNode* prev=res;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            if(cur->val==val)   prev->next=cur->next;
            else    prev=cur;
            cur=cur->next;
        }
        return res->next;*/
        //递归
        if(head==NULL)
            return head;
        head->next=removeElements(head->next,val);
        if(head->val==val)
            return head->next;
        else
            return head;
    }
};