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
    bool isPalindrome(ListNode* head) {
        // if(head==nullptr||head->next == nullptr)return true;
        // int len = 1;
        // ListNode* node = head;
        // while(node->next){
        //     node = node->next;
        //     len++;
        // }
        // int l = len/2;
        // node = head;
        // stack<ListNode*> st;
        // while(l--){
        //     st.push(node);
        //     node = node->next;
        // }
        // if(len%2==1)node = node->next;
        // while(!st.empty()){
        //     auto n = st.top();
        //     st.pop();
        //     if(n->val!=node->val)return false;
        //     node = node->next;
        // }
        // return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        ListNode* prepre = nullptr;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = prepre;
            prepre = pre;
        }
        if(fast){
            slow = slow->next;
        }
        while(pre&&slow){
            if(pre->val!=slow->val)return false;
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};
