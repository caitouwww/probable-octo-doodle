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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*ListNode* A=headA;
        while(A!=NULL)
        {
            ListNode* B=headB;
            while(B!=NULL)
            {
                if(B!=A)
                {
                    B=B->next;
                }
                else
                    return B;
            }
            A=A->next;
        }
        return A;*/
        if(headA==NULL&&headB==NULL)
            return headA;
        ListNode* A=headA;
        ListNode* B=headB;
        while(A!=B)
        {
            if(A==NULL) A=headB;
            else    A=A->next;
            if(B==NULL) B=headA;
            else    B=B->next;
        }
        return A;
    }
};