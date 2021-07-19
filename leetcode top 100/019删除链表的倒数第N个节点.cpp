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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int nn = n;
        ListNode* first = head;
        while(first&&nn){
            first = first->next;
            nn--;
        }
        if(first==nullptr&&nn==0){
            dummy->next = head->next;
            head->next = nullptr;
            return dummy->next;
        }
        ListNode* second = head;
        while(first->next){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
        //  ListNode* slow = head, *fast = head;
        // for(int i = 0; i < n; ++i){
        //     fast = fast->next;
        // }
        // if(!fast)   return head->next;
        // while(fast->next){
        //     fast = fast->next;
        //     slow = slow->next;
        // }
        // slow->next = slow->next->next;
        // return head;
    }
};
