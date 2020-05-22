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
    //×ÔÐ´
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     ListNode* tmp1 = l1;
    //     ListNode* tmp2 = l2;
    //     if(isZero(tmp1))    return l2;
    //     if(isZero(tmp2))    return l1;
    //     tmp1 = l1;
    //     tmp2 = l2;
    //     int sum = tmp1->val + tmp2->val;
    //     int carry = sum >= 10 ? 1 : 0;
    //     int left = sum % 10;
    //     ListNode* res = new ListNode(left);
    //     ListNode* head = res;
    //     tmp1 = tmp1->next;
    //     tmp2 = tmp2->next;
    //     if(tmp1 == nullptr && tmp2 == nullptr){
    //         if(carry == 1)  res->next = new ListNode(carry);
    //     }
    //     while(tmp1 != nullptr && tmp2 != nullptr){
    //         sum = tmp1->val + tmp2->val + carry;
    //         carry = sum >= 10 ? 1 : 0;
    //         left = sum % 10;
    //         res->next = new ListNode(left);
    //         res = res->next;
    //         tmp1 = tmp1->next;
    //         tmp2 = tmp2->next;
    //     }
    //     while(tmp1 != nullptr){
    //         sum = tmp1->val + carry;
    //         carry = sum >= 10 ? 1 : 0;
    //         left = sum % 10;
    //         res->next = new ListNode(left);
    //         res = res->next;
    //         tmp1 = tmp1->next;
    //     }
    //     while(tmp2 != nullptr){
    //         sum = tmp2->val + carry;
    //         carry = sum >= 10 ? 1 : 0;
    //         left = sum % 10;
    //         res->next = new ListNode(left);
    //         res = res->next;
    //         tmp2 = tmp2->next;
    //     }
    //     if(carry)   res->next = new ListNode(carry);
    //     return head;
    // }
    // bool isZero(ListNode* node){
    //     if(node->val == 0){
    //         while(node != NULL){
    //             if(node->val != 0)  return false;
    //             else    node = node->next;
    //         }
    //         return true;
    //     }else   return false;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int l1val = l1 != nullptr ? l1->val : 0;
            int l2val = l2 != nullptr ? l2->val : 0;
            int sum = l1val + l2val + carry;
            carry = sum / 10;

            ListNode* sumNode = new ListNode(sum % 10);
            cur->next = sumNode;
            cur = cur->next;

            if(l1 != nullptr)   l1 = l1->next;
            if(l2 != nullptr)   l2 = l2->next;
        }
        return dummy->next;
    }
};