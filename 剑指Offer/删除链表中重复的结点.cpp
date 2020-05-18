/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* p = new ListNode(NULL);
        p->next = pHead;
        pHead = p;
        ListNode* left;
        ListNode* right;
        while(p->next){
            left = p->next;
            right = left;
            while(right->next != NULL && right->next->val == left->val)    right = right->next;
            if(left == right)    p = p->next;
            else    p->next = right->next;
        }
        return pHead->next;
    }
};