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
    ListNode* ReverseList(ListNode* head) {
        ListNode* p = NULL;
        ListNode* q = head;
        if(q == NULL)    return head;
        ListNode* r = head->next;
        if(r == NULL)    return head;
        while(r != NULL){
            q->next = p;
            if(r->next == NULL){
                r->next = q;
                break;
            }else{
                p = q;
                q = r;
                r = r->next;
            }
        }
        return r;
    }
};
