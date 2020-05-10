/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    //递归的解法，实际上是栈的解法，可以用栈的前进后出特性，当链表非常长的时候，用栈更合适
    /*void recursive(ListNode* head){
        if(head == NULL)    return;
        recursive(head->next);
        res.push_back(head->val);
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        recursive(head);
        return res;
    }*/
    vector<int> printListFromTailToHead(ListNode* head){
        //翻转链表，再依次输出
        if(head == NULL)    return res;
        if(head->next == NULL){
            res.push_back(head->val);
            return res;
        }
        ListNode* dummy = new ListNode(NULL);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = head;
        ListNode* r = head->next;
         
        p->next = NULL;
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
        while(r!=dummy){
            res.push_back(r->val);
            r = r->next;
        }
        return res;
    }
private:
    vector<int> res;
};