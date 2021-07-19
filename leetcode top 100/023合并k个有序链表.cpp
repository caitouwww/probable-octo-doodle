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
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int n = lists.size();
//         if(!n)return nullptr;
//         else if(n==1)return lists[0];
//         else if(n==2)return merge2Lists(lists[0],lists[1]);
//         else{
//             int mid = n/2;
//             vector<ListNode*> l1(mid,nullptr);
//             for(int i = 0; i < mid; ++i)l1[i] = lists[i];
//             vector<ListNode*> l2(n-mid,nullptr);
//             for(int i = mid; i < n; ++i)l2[i-mid] = lists[i];
//             return merge2Lists(mergeKLists(l1),mergeKLists(l2));
//         }
//     }
// private:
//     // ListNode* merge2Lists(ListNode* l1, ListNode* l2){
//     //     ListNode* dummy = new ListNode(0);
//     //     ListNode* node = dummy;
//     //     while(l1&&l2){
//     //         if(l1->val<=l2->val){
//     //             node->next = l1;
//     //             l1 = l1->next;
//     //         }else{
//     //             node->next = l2;
//     //             l2 = l2->next;
//     //         }
//     //         node = node->next;
//     //     }
//     //     if(l1)node->next = l1;
//     //     else node->next = l2;
//     //     return dummy->next;
//     // }
//     ListNode* merge2Lists(ListNode* l1, ListNode* l2){
//         if(l1==nullptr)return l2;
//         else if(l2==nullptr)return l1;
//         // ListNode* head = new ListNode(0);
//         ListNode* head = nullptr;
//         if(l1->val<=l2->val){
//             // head->next = l1;
//             head = l1;
//             l1->next = merge2Lists(l1->next,l2);
//         }else{
//             // head->next = l2;
//             head = l2;
//             l2->next = merge2Lists(l1,l2->next);
//         }
//         // return head->next;
//         return head;
//     }
// };
class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*> lists){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int n = lists.size();
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        // for(int i = 0; i < n; ++i){
        //     pq.push(lists[i]);
        // }
        for(auto x:lists)
            if(x)pq.push(x);
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if(node->next)pq.push(node->next);
        }
        return dummy->next;
    }
private:
    struct compare{
        bool operator()(ListNode* l1,ListNode* l2){
            return l1->val > l2->val;
        }
    };
};
