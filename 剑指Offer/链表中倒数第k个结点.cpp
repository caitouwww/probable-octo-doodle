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
    ListNode* FindKthToTail(ListNode* head, unsigned int k) {
        int node = 0;
        ListNode* help = head;
        while(help != NULL){
            node++;
            help = help->next;
        }
        ListNode* res = head;
        if(k > node)    return NULL;
        if(k == node)    return head;
        //res = head;
        node = node - k;
        while(node > 0){
            res = res->next;
            node--;
        }
        return res;
    }
};
