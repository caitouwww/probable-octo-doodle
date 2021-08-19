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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                hasCycle = true;
                break;
            }
        }
        if(hasCycle){
            while(head!=slow){
                head = head->next;
                slow = slow->next;
            }
            return head;
        }else return nullptr;
    }
};
