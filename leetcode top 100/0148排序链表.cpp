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
//     ListNode* sortList(ListNode* head) {
//         return mergeSort(head);
//     }
//     ListNode* mergeSort(ListNode* head){
//         if(head==nullptr||head->next==nullptr)return head;
//         ListNode* slow = head, *fast = head,*pre = nullptr;
//         while(fast!=nullptr&&fast->next!=nullptr){
//             pre = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         pre->next = nullptr;
//         ListNode* l =  mergeSort(head);
//         ListNode* r =  mergeSort(slow);
//         return merge(l,r);
//     }
//     ListNode* merge(ListNode* l, ListNode* r){
//         if(l==nullptr)return r;
//         else if(r==nullptr)return l;
//         if(l->val <= r->val){
//             l->next = merge(l->next,r);
//             return l;
//         }else{
//             r->next = merge(l,r->next);
//             return r;
//         }
//     }
// };
// class Solution{
// public:
//     ListNode* sortList(ListNode* head) {
//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;
//         ListNode* node = head;
//         int length = 0;
//         while (node) {
//             length++;
//             node = node->next;
//         }
//         for (int size = 1; size < length; size <<= 1) {
//             ListNode* cur = dummy->next;
//             ListNode* tail = dummy;
//             while (cur) {
//                 auto left = cur;
//                 auto right = cut(left,size);
//                 cur = cut(right,size);
//                 tail->next = merge(left,right);
//                 while(tail->next){
//                     tail = tail->next;
//                 }
//             }
//         }
//         return dummy->next;
//     }
//     ListNode* cut(ListNode* left, int size) {
//         ListNode* p = left;
//         while(--size&&p) {
//             p = p->next;
//         }
//         if(!p) return nullptr;
//         ListNode* next = p->next;
//         p->next = nullptr;
//         return next;
//     }
//     ListNode* merge(ListNode* l, ListNode* r){
//         ListNode* dummy = new ListNode(0);
//         ListNode* node = dummy;
//         while (l && r) {
//             if(l->val <= r->val) {
//                 node->next = l;
//                 node = node->next;
//                 l = l->next;
//             }else{
//                 node->next = r;
//                 node = node->next;
//                 r = r->next;
//             }
//         }
//         if (l) {
//             node->next = l;
//         }else {
//             node->next = r;
//         }
//         return dummy->next;
//     }
// };

class Solution{
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        return quickSort(newHead, nullptr);
    }
    ListNode* quickSort(ListNode* head, ListNode* end) {
        if(head == end || head->next == end || head->next->next == end) return head;
        ListNode* tmpHead = new ListNode(-1);
        ListNode* partition = head->next, *p = partition, *tp = tmpHead;
        while (p->next != end) {
            if (p->next->val < partition->val) {
                tp->next = p->next;
                tp = tp->next;
                p->next = p->next->next;
            }else {
                p = p->next;
            }
        }
        tp->next = head->next;
        head->next = tmpHead->next;
        quickSort(head, partition);
        quickSort(partition, end);
        return head->next;
    }
};
