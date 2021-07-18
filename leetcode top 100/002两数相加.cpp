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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* dummy = new ListNode(0);
         ListNode* node = dummy;
         int add = 0, val = 0,sum = 0;
         while(l1||l2||add){
             if(l1&&l2){
                 sum = l1->val+l2->val+add;
             }else if(l1){
                 sum = l1->val+add;
             }else if(l2){
                 sum = l2->val+add;
             }else sum = add;
             add = sum/10;
             ListNode* cur = new ListNode(sum%10);
             node->next = cur;
             node = node->next;
             if(l1)l1 = l1->next;
             if(l2)l2 = l2->next;
         }
         return dummy->next;
//        ListNode* dummy = new ListNode(0);
//        ListNode* cur = dummy;
//        int carry = 0;
//        while(l1 != nullptr || l2 != nullptr || carry != 0){
//            int l1val = l1 != nullptr ? l1->val : 0;
//            int l2val = l2 != nullptr ? l2->val : 0;
//            int sum = l1val + l2val + carry;
//            carry = sum / 10;
//
//            ListNode* sumNode = new ListNode(sum % 10);
//            cur->next = sumNode;
//            cur = cur->next;
//
//            if(l1 != nullptr)   l1 = l1->next;
//            if(l2 != nullptr)   l2 = l2->next;
//        }
//        return dummy->next;
    }
};
