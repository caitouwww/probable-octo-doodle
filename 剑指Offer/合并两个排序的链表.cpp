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
    ListNode* Merge(ListNode* head1, ListNode* head2)
    {
        ListNode* res = NULL;
        ListNode* h1 = head1;
        ListNode* h2 = head2;
        if(head1 == NULL)    return head2;
        if(head2 == NULL)    return head1;
        if(head1->val < head2->val){
            res = head1;
            h1 = h1->next;
        }
        else{
            res = head2;
            h2 = h2->next;
        }
        ListNode* rs = res;
        while(h1 != NULL || h2 != NULL){
            if(h1 != NULL && h2 != NULL){
                if(h1->val < h2->val){
                    rs->next = h1;
                    rs = rs->next;
                    h1 = h1->next;
                }else{
                    rs->next = h2;
                    rs = rs->next;
                    h2 = h2->next;
                }
            }else if(h1 == NULL){
                rs->next = h2;
                break;
            }else if(h2 == NULL){
                rs->next = h1;
                break;
            }
        }
        return res;
    }
};
