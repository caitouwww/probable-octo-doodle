/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL && pHead2 == NULL)    return NULL;
        ListNode* a = pHead1;
        ListNode* b = pHead2;
        while(a != b){
            if(a == NULL)    a = pHead2;
            else    a = a->next;
            if(b == NULL)    b = pHead1;
            else    b = b->next;
        }
        return a;
    }
};