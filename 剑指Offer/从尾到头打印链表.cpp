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
    //�ݹ�Ľⷨ��ʵ������ջ�Ľⷨ��������ջ��ǰ��������ԣ�������ǳ�����ʱ����ջ������
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
        //��ת�������������
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