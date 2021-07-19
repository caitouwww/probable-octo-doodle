/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        else if(!l2)return l1;
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                node->next = l1;
                node = node->next;
                l1 = l1->next;
            }else{
                node->next = l2;
                node = node->next;
                l2 = l2->next;
            }
        }
        if(l1){
            node->next = l1;
        }else{
            node->next = l2;
        }
        return dummy->next;
    }
};
